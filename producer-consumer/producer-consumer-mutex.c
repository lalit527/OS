#include<stdio.h>
#include<stdlib.h>

int temp = 0, overflow = 0, mutex = 1, underflow = 10;

int wait_thread(int counter) {
    return --counter;
}

int signal_thread(int counter) {
    return ++counter;
}

void producer() {
    mutex = wait_thread(mutex);
    overflow = signal_thread(overflow);
    underflow = wait_thread(underflow);
    ++temp;
    printf("\nProducer:\t Element %d\n", temp);
    mutex = signal_thread(mutex);
}

void consumer() {
    mutex = wait_thread(mutex);
    overflow = wait_thread(overflow);
    underflow = signal_thread(underflow);
    printf("\nConsumer:\t Element %d\n", temp);
    temp--;
    mutex = signal_thread(mutex);
}

int main() {
    int choice;
    printf("\n1.Producer\t");
    printf("\n2.Consumer\t");
    printf("\n3.Quit\t");
    while(1) {
        printf("\nEnter your choise:\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1: if((mutex == 1) && (underflow != 0)) {
                        producer();
                    }else{
                        printf("Buffer Overflow\n");
                    }
                    break;
            case 2: if((mutex == 1) && (overflow != 0)) {
                        consumer();
                    }else{
                        printf("Buffer Underflow\n");
                    }
                    break;
            case 3: exit(0);
                    break;
            default: exit(0);
        }
    }
    return 0;
}