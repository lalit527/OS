#include <stdio.h>
#define N 4
int main() {
    int frame[N];
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    for(int i=0; i<N; i++) {
        frame[i] = -1;
    }

    int length = sizeof(pages) / sizeof(pages[0]);
    int page_faults = 0;
    int j = N-1;
    for(int i=0; i<length; i++) {
        if(frame[j] == -1) {
            frame[j] = pages[i];
            ++j;    
        }
        int k = 0;
        while(k < N) {
            if(frame[k] == pages[i]) {
                break;
            }else{
                ++k;
            }
        }
        ++page_faults;
        int temp = frame[0];
        for(int k = 0; k<N-1; k++) {
            frame[k] = frame[k+1]; 
        }
        frame[k] = pages[i];
    }
    
    printf("%d", page_faults);
}