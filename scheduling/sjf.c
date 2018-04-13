typedef int bool;
#define true 1
#define false 0
#define INT_MAX 99999

#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int art;
};
// int main() {
//     int size = 4;
//     int waiting[size];
//     int duration[4] = {6, 8, 7, 3};
//     int arrival[4] = {0, 1, 2, 3};
//     int length = sizeof(duration)/sizeof(duration[0]);
//     int remainingJob[length];
//     bool done = false;
//     int count = 50;
//     printf("The length of array is %d\n", length);
//     for(int i = 0; i < length; ++i) {
//         remainingJob[i] = duration[i];
//     }
//     while(!done) {
//         int max = -99;
//         for(int i = 0; i < length; i++) {
//             if(remainingJob[i] == 0) {
//                 done = true;
//             }else {
//                 done = false;
//             }
//             for(int j = 0; j <= i; j++) {
//                 if(remainingJob[j] <= 0) {
//                     continue;
//                 }
//                 if(remainingJob[]) {

//                 }
//                 remainingJob[j] = remainingJob[j] - 1;
//             }
//             --count;
//             if(count == 0) {
//                 break;
//             }
            
//         }
//         if(count == 0) {
//             break;
//         }
//     }

//     for(int i = 0; i < length; i++) {
//         printf("%d", remainingJob[i]);
//     }
//     printf("%d\n", count);

// }
void findWaitTime(struct Process proc[], int n, int wait[]) {
    int run[n];
    for (int i = 0; i < n; i++) {
        run[i] = proc[i].bt;
    }

    int complete = 0, time = 0, min = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {
        for(int j = 0; j < n; j++) {
            if((proc[j].art <= time) && (run[j] < min) && (run[j] > 0)) {
                min = run[j];
                shortest = j;
                check = true;
            }
        }

        if(check == false) {
            ++time;
            continue;
        }
        run[shortest]--;
        min = run[shortest];

        if (min == 0) {
            min = INT_MAX;
        }

        if(run[shortest] == 0) {
            complete++;
        }

        finish_time = time + 1;

        wait[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

        if(wait[shortest] < 0) {
            wait[shortest] = 0;
        }

        ++time;
    }    
}

void findTurnTime(struct Process proc[], int n, int wait[], int turn[]) {
    for(int i = 0; i < n; i++) {
        turn[i] = proc[i].bt + wait[i];
    }
}

void findavgTime(struct Process proc[], int n) {
    int wait[n], turn[n], total_wait = 0, total_turn = 0;

    findWaitTime(proc, n, wait);
    findTurnTime(proc, n, wait, turn);

    for(int i = 0; i < n; i++) {
        total_wait = total_wait + wait[i];
        total_turn = total_turn + turn[i];
        printf("%d", proc[i].pid);
        printf("%d", proc[i].bt);
        printf("%d", proc[i].art);
        printf("\n");
    }

    printf("Total Wait%f\n", (float)total_wait / (float)n);
    printf("Total Wait%f\n", (float)total_turn / (float)n);
}

int main() {
    struct Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
                    { 3, 7, 2 }, { 4, 3, 3 } };
    int n = sizeof(proc)/ sizeof(proc[0]);
    findavgTime(proc, n);
    return 0;
}