#include <stdio.h>
#include <stdlib.h>

//void sort(short* array, short size);
typedef struct _stsss
{
    int count;
    short number;
}ISST;


int main(void){
    char tf =0;
    int size = 0, ptrsize = 1;
    short temp = 0;

    ISST temp_isst;
    ISST* isstp =(ISST*) malloc(sizeof(ISST) * ptrsize);

    scanf("%d", &size);
    //printf("size >>>> %d", size);

    scanf("%hd", &temp); // %d로 잡으면 그냥 이전 int를 초기화 시켜버리네?

    isstp -> number = temp;
    isstp -> count = 1;

    for(int i=0; i<size-1; i++){

        scanf("%hd", &temp);
        for(int st_size =0; st_size<ptrsize; st_size++){
            if((isstp + st_size) -> number == temp){
                (isstp + st_size) -> count++;
                tf = 1;
            }
        }

        if(!tf){
            ptrsize = ptrsize + 1;
            isstp = (ISST*) realloc(isstp, sizeof(ISST) * ptrsize);
            for(int i =0; i < ptrsize-1; i++){
                if(temp < (isstp + i) -> number){
                    for(int j = ptrsize-1; j>i; j--){
                        *(isstp + (j)) = *(isstp + (j-1)); 
                    }
                    (isstp + i) -> count = 1;
                    (isstp + i) -> number = temp;
                    break;
                }
            }
        }
        // //이미 소팅이 되어 있는 상태를 가정
        // for(int i =0; i<ptrsize-1; i++){
        //     for(int j=0; j<ptrsize-1-i; j++){
        //         if((isstp + j) -> number > (isstp + j + 1) -> number){
        //             temp_isst = *(isstp + j + 1);
        //             *(isstp + j + 1) = *(isstp + j);
        //             *(isstp + j) = temp_isst;
        //         }

        //     }

        // }
        tf = 0;
        
    }

    for(int i =0; i < ptrsize; i++){
        for(int j=0; j<(isstp +i) -> count; j++){
            printf("%hd\n",(isstp + i) -> number);
        }
    }
    
}