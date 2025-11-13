#include <stdio.h>
#include <stdlib.h>
// #define MAX_P_2751 1000000
// int array[MAX_P_2751]= {0,};

int main(void){
    int case_size =0, temp =0, fore_index =0, fore_number = 0;
    int* array = NULL;
    /*
        int array[1000000]= {0,}; // this has problem, I think maybe the size of
        array has some crash, 
        becaus too much array size(memory size) in the function

    */
   
    // take : case size input
    scanf("%d", &case_size);
    array = (int*) malloc(sizeof(int) * case_size);
    scanf("%d", &temp);
    array[0] = temp;
    fore_index = 0;
    fore_number = temp;

    for(int loop_index = 1; loop_index < case_size; loop_index++){
        scanf("%d", &temp);
        array[loop_index] = temp;
        if(temp > fore_number){
            for(int tail_loop_index = fore_index; tail_loop_index < loop_index; tail_loop_index++){
                if(temp < array[tail_loop_index]){
                    for(int i = loop_index; i > tail_loop_index; i--){
                        array[i] = array[i-1];
                    }
                    array[tail_loop_index] = temp;
                    fore_index = tail_loop_index;
                    fore_number = temp;
                    break;
                }
            }
        }else{
            for(int head_loop_index = 0; head_loop_index < fore_index; head_loop_index++){
                if(temp < array[head_loop_index]){
                    for(int i = loop_index; i > head_loop_index; i--){
                        array[i] = array[i-1];
                    }
                    array[head_loop_index] = temp;
                    fore_index = head_loop_index;
                    fore_number = temp;
                    break;
                }
            }
        }
        // for(int j=0; j < loop_index; j++){
        //     if(temp < array[j]){
        //         for(int i = loop_index; i > j; i--){
        //             array[i] = array[i -1];      
        //         }
        //         array[j] = temp;
        //         fore_index = j;
        //         break;
        //     }
        // }  // time over
    }
    for(int i=0; i < case_size; i++){
        printf("%d\n", array[i]);
    }

    // printf("program end\n");
    return 0;
}
