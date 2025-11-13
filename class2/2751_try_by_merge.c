#include <stdio.h>
#include <stdlib.h>

void mergeSort(int * array, int low, int high, int * temp_array);
void printArray(int* array, int size);


int main(void){
    int* answer_array = NULL,* temp_array = NULL;
    int case_size = 0;

    // int test[10] = {5,8,7,6,9,1,2,0,3,4};
    // int temp[10] = {0,};
    // int* testp = test;
    // int* tempp = temp;
    // printArray(testp, 10);
    
    // mergeSort(testp, 0, 9, tempp);

    // printArray(testp, 10);


    scanf("%d", &case_size);

    answer_array = (int *) malloc(sizeof(int)*case_size);
    temp_array = (int *) malloc(sizeof(int)*case_size);

    for(int loop = 0; loop < case_size; ++loop){
        scanf("%d", (answer_array + loop));
    }
    // printArray(answer_array, case_size);

    mergeSort(answer_array, 0, case_size-1, temp_array); // casesize -1 is important
    printArray(answer_array, case_size);
    return 0;
}

void mergeSort(int* array, int low, int high, int * temp_array){
    //printArray(array, 10);
    if(low >= high){
        return;
    } // basic condition

    int mid = (low + high) / 2;
    //divide
    
    mergeSort(array, low, mid, temp_array);
    mergeSort(array, mid + 1, high, temp_array);
    //conquer

    int left_condition = low, right_conditon = mid + 1, now_index = low;
    for( ; now_index <= high; ++now_index){
        if(right_conditon > high){
            *(temp_array + now_index) = *(array + left_condition);
            left_condition++;
        }else if(left_condition > mid){
            *(temp_array + now_index) = *(array + right_conditon);
            right_conditon++;
        }else if(*(array + left_condition) <= *(array + right_conditon)){
            *(temp_array + now_index) = *(array + left_condition);
            left_condition++;
        }else /*mean, *(array + left_condition) > *(array + right_conditon)*/{
            *(temp_array + now_index) = *(array + right_conditon);
            right_conditon++;
        }
    }

    for(now_index = low; now_index <= high; now_index++){
        *(array + now_index) = *(temp_array + now_index); 
    }

}

void printArray(int* array, int size){
    // printf("\nprint start\n");
    for(int i =0; i < size; i++){
        printf("%d\n", *(array + i));
    }
    // printf("\nprint end\n");
}