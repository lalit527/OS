#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#include <stdlib.h>

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *args) {
    int id = *((int*)args);
    ++rcount;
    sem_wait(&mutex);
      if(rcount == 1) {
          sem_wait(&writeblock);
      }
      sem_post(&mutex);
      printf("Data read by the reader%d is %d\n", id, data);
    sem_post(&mutex);
    usleep(1000 * (random() % 5));
    sem_wait(&mutex);
      --rcount;
      if(rcount == 0) {
          sem_post(&writeblock);
      }
    sem_post(&mutex);
   
}

void *writer(void *args) {
    int id = *((int*)args);
    sem_wait(&writeblock);
      data++;
      printf("Data written by the writer%d is %d\n", id, data);
      usleep(1000 * (random() % 5));
    sem_post(&writeblock);
}

int main() {
    //int i,b;
    pthread_t rthreadID[5], wthreadID[5];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);
    for(int i = 0; i < 2; i++) {
        pthread_create(&wthreadID[i], NULL, writer, (void *)i);
        pthread_create(&rthreadID[i], NULL, reader, (void *)i);
    }
    for(int i = 0; i < 2; i++) {
        pthread_join(wthreadID[i], NULL);
        pthread_join(rthreadID[i], NULL);
    }
    return 0;
}