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
    int j = 0;
    for(int i=0; i<length; i++) {
        int flag = 0;
        if(j < N && frame[j] == -1) {
            frame[j] = pages[i];
            ++j;    
        }else{
            int k = 0;
            while(k < N) {
                if(frame[k] == pages[i]) {
                    flag = 1;
                    break;
                }else{
                    ++k;
                }
            }
            if(flag == 0) {
                ++page_faults;
                int temp = frame[0];
                for(int l = 1; l<N; l++) {
                    frame[l] = frame[l+1]; 
                }
                frame[k] = pages[i];
            }
        }                
    }
    
    printf("%d\n", page_faults);

    for(int i = 0; i <  N; i++) {
        printf("%d\n", frame[i]);
    }
}