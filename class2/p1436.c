/*
종말의 수
N번째로 작은 3개의 "연속"된 6(666)을 포함하는 수
666 1666 2666.... 5666 6666(X) 6660 6666 7666 8666 9666 10666 11666 12666 13666 14666 16660 16666 17666


666을 10으로 최대한 쪼개봐 => 자리수 획득
666/10 = 66
66/10 = 6
6/10 = 0
*/

#include <stdio.h>



int main(void){
    // printf("%d %d %d", 666/10, 66/10, 0/10);
    int counter = 1, input = 0, temp =0;
    scanf("%d", &input);
    temp = input;
    while(1){
        temp = temp /10;
        if(temp == 0){
            break;
        }
        counter++;
    }
    printf("%d", counter);
    return 0;
}