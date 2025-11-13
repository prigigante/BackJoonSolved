/**
 * 처음 입력 N개(500,000이하)
 * 입력되는 숫자의 크기는 +-10,000,000사이
 * 
 * 맞춰야하는 대답의 개수는 m개( 500,000 under)
 * range(-10000000, 10000000)
 */



#include <stdio.h>

#define ADD_MACRO 10000000


int array[20000001] = {0,};

int main(void){
    int case_size = 0, temp_input = 0, added_number = 0;

    scanf("%d", &case_size);
    for(int i =0; i < case_size; i++){
        scanf("%d", &temp_input);
        added_number = temp_input + ADD_MACRO;
        array[added_number]++;
    }

    scanf("%d", &case_size);
    for(int i =0; i < case_size; i++){
        scanf("%d", &temp_input);
        added_number = temp_input + ADD_MACRO;
        printf("%d ", array[added_number]);
    }
    return 0;
}