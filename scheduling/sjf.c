typedef int bool;
#define true 1
#define false 0

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

void findavgTime(struct Process proc[], int n) {
    printf("%d\n", proc[0].art);
    for(int i = 0; i < n; i++) {
        printf("%d", proc[i].pid);
        printf("%d", proc[i].bt);
        printf("%d", proc[i].art);
        printf("\n");
    }
}

int main() {
    struct Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
                    { 3, 7, 2 }, { 4, 3, 3 } };
    int n = sizeof(proc)/ sizeof(proc[0]);
    findavgTime(proc, n);
    return 0;
}