#include <stdio.h>


int main(){

    int Q3_input = 6;
    int counts = 0;
    int perfect[10];

    for(int i = 2; i <= Q3_input; i++){
        int sum = 0;
        for(int j = 1; j <= i/2; j++){
            if(i % j == 0){
                sum += j;
            }
        }
        if(sum == i){
            perfect[counts] = i;
            counts ++;
            //printf("%d",counts);
        }
    }
    //printf("%d",counts);
    for (int i = 0; i < counts; i++){
        printf("%d\n",perfect[i]);
    }
    

    return 0;
}


