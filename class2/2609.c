#include <stdio.h>

int getMaxDivisor(int a, int b);

int main(void){
    int input1 = 0, input2 = 0, bigger =0, greatest_common_divisor =1;
    long long least_common_multiple =1;
    scanf("%d %d", &input1, &input2);
    greatest_common_divisor = getMaxDivisor(input1, input2);
    //printf("%d <<<<" , greatest_common_divisor);
    least_common_multiple = greatest_common_divisor * (input1/greatest_common_divisor) * (input2/greatest_common_divisor);
    //printf(">>> %d", least_common_multiple);
    printf("%d\n%llu", greatest_common_divisor, least_common_multiple);
    return 0;
}

int getMaxDivisor(int num1, int num2){
    int smaller =0, maximum_divisor =1, count = 1;
  
    if(num1 > num2){
        smaller = num2;
    }else{
        smaller = num1;
    }

    if(smaller == 1){
        return 1;
    }
    for(int i=2; i<=smaller; i++){
        if(num1 % i ==0 && num2 % i == 0){
            maximum_divisor = i;
        }
    }
    return maximum_divisor;
}