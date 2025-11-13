#include <stdio.h>


int main(void){
    int input_size = 0, now_index = 0, input = 0;
    int array[100000] = {0,};
    int sum = 0;
    scanf("%d", &input_size);
    
    for(int i =0; i < input_size; i++){
        scanf("%d", &input);
        if(input == 0){
            array[now_index] = 0;
            now_index--;
        }else{
            array[now_index] = input;
            now_index++;
        }
    }
    
    for(int i = 0; i < now_index; i++){
        sum = sum + array[i];
    }
    
    printf("%d", sum);
    return 0;

}