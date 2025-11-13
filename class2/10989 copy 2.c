#include <stdio.h>
#include <stdlib.h>

//void sort(short* array, short size);

int main(void){
    // N개의 수를 오름차순으로 정렬
    short size =0, temp =0;
    

    scanf("%d", &size);
    // ptr = (short*) malloc(sizeof(short) * size);
    short* ptr =(short*) malloc(sizeof(short)*size);
    // short ptr[size];
    for(short i=0; i<size; i++){
        scanf("%d", &ptr[i]);
    }
    // printf("====== input ======\n");
    // for(short i=0; i<size; i++){
    //     printf("%d\n",ptr[i]);
    // }
    // printf("============\n");
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(ptr[j] > ptr[j+1]){
                temp = ptr[j+1];
                ptr[j+1] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    // sort(ptr, size);
    //prshortf("====================\n");
    for(short i=0; i<size; i++){
        printf("%d\n",ptr[i]);
    }
    return 0;


}

// void sort(short* iptr, short size){
//     short temp = 0;
//     for(int i=0; i<size-1; i++){
//         for(int j=0; j<size-i-1; j++){
//             if(*(iptr + j) > *(iptr + j+1)){
//                 temp = *(iptr + j+1);
//                 *(iptr + j + 1) = *(iptr + j);
//                 *(iptr +j) = temp;
//             }
//         }
//     }
// }