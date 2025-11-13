#include <stdio.h>
// #include <stdlib.h>

//void sort(short* array, short size);

short main(void){
    // N개의 수를 오름차순으로 정렬
    short size =0;
    short* ptr = NULL;

    scanf("%d", &size);
    // ptr = (short*) malloc(sizeof(short) * size);
    
    for(short i=0; i<size; i++){
        scanf("%d", (ptr + i));
    }
    
    sort(ptr, size);
    //prshortf("====================\n");
    for(short i=0; i<size; i++){
        printf("%d\n", *(ptr + i));
    }
    free(ptr);
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