#include <stdio.h>

#define MAX_P_2751 1000000
int array[MAX_P_2751]= {0,};
void sortAscP2751(int now_index);

int main(void){
    int case_size =0, temp =0, index =0;
    /*
        int array[1000000]= {0,}; // this has problem, I think maybe the size of
        array has some crash, 
        becaus too much array size(memory size) in the function

    */
   
    // take : case size input
    scanf("%d", &case_size);
    for(int loop = 0; loop < case_size; loop++){
        scanf("%d",&temp);
        array[loop] = temp;
        
        // sortAscP2751(loop);
    }
    for(int loop = 0; loop < case_size; loop++){
        printf("%d\n", array[loop]);
    }
    // printf("program end\n");
    return 0;
}

void sortAscP2751(int index){
    // printf("fucntion start\n");
    int target = *(array + index);
    // printf("%d <<< target\n", target);
    for(int i=0; i<index; i++){
        // printf("fucntion's loop start\n");
        if(target < *(array + i)){
            for(int j=index; j>i; j--){
                *(array + j) = *(array + (j-1));
            }
            *(array + i) = target;
            break;
        }
    }
}