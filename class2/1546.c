#include <stdio.h>
#include <stdlib.h>

int main(void){
    int count = 0, temp = 0, max = -1;
    double sum = 0;
    int* ip = NULL;
    double* dp  = NULL;
    scanf("%d", &count);
    ip = (int*) malloc(sizeof(int) * (count));
    dp = (double*) malloc(sizeof(double) * (count + 1)); 
    
    for(int i =0; i < count; i++){
        scanf("%d", &temp);
        if(temp > max){
            max = temp;
        }
        *(ip + i) = temp;
    }
    for(int i =0; i < count; i ++){
        sum = sum +     ((double) *(ip + i) / (double) max) * 100;
    }
    printf("%6f", sum/count );
}