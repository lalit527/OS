#include <stdio.h>
struct process {
    char name;
    int at, bt, wt, tt, rt;
    int completed;
    float ntt;
}p[10];
int n;
int queue[10];
int front=-1, rear=-1;
void enqueue(int i) {
    if(rear == 10) {
        printf("overflow");
    }else {
        ++rear;
        queue[rear] = i;
        if(front == -1) {
            front = 0;
        }
    }
}

int dequeue() {
    if(front == -1) {
        printf("underflow");
    }else {
        int temp = queue[front];
        if(front == rear) {
            front = rear = -1;
        }else{
            ++front;
        }
        return temp;
    }
    return -1;
}

int isInQueue(int i) {
    int k;
    for(k = front; k <= rear; k++) {
        if(queue[k] == i) {
            return 1;
        }
    }
    return 0;
}

void sortByArrival() {
    struct process temp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++) {
            if(p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
int main() {
    int i, j, time=0, total = 0, sum_bt = 0, tq;
    char c;
    float avgwt = 0;
    printf("Enter no of processes");
    scanf("%d", &n);
    for(i = 0, c = 'A'; i<n; i++, c++) {
        p[i].name = c;
        printf("\nEnter the arrival time and burst time of process %c: ",p[i].name);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
        sum_bt += p[i].bt;
    }
    printf("\nEnter the time slice:");
    scanf("%d",&tq);
    sortByArrival();
    enqueue(0);
    printf("Process execution order: ");
    for(time=p[0].at; time<=sum_bt;) {
        i = dequeue();
        if(p[i].rt <= tq) {
            time += p[i].rt;
            p[i].rt = 0;
            p[i].completed = 1;
            printf(" %c %d \n", p[i].name, p[i].rt);
            p[i].wt = time - p[i].at - p[i].bt;
            p[i].tt = time - p[i].at;
            p[i].ntt = ((float)p[i].tt / p[i].bt);
            for(j = 0; j < n; j++) {
                if(p[j].at <= time && p[j].completed != 1 && isInQueue(j) != 1 && p[j].rt > 0) {
                    enqueue(j);
                }
            }
        }else {
            time += tq;
            p[i].rt -= tq;
            printf(" %c %d \n", p[i].name, p[i].rt);
            for(j=0; j<n; j++){
                if(p[j].at <= time && p[j].completed != 1 && isInQueue(j) != 1 && p[j].rt > 0) {
                    enqueue(j);
                }
            }
            if(p[i].rt > 0) {
                enqueue(i);
            }
            
        }
    }

    printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\t Normalized TT");
    for(i = 0; i < n; i++) {
        avgwt += p[i].wt;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].ntt);
    }
    printf("\nAverage waiting time:%f\n",avgwt/n);
    return 0;
}