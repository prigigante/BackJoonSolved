#include <stdio.h>


int main(void){
    int count =0;
    char array[6];
    char* p = array;
    while(1){
        gets(array);
        if(array[0] == '0'){
            break;
        }
        while(*(p + count)){
            count++;
        }
        switch (count)
        {
        case 1:
            printf("yes\n");
            break;
        case 2:
            if(*(p + 0) == *(p+1)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
            break;
        case 3:
            if(*(p+0) == *(p+2)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
            break;
        case 4:
            if(*(p +0) == *(p+3) && *(p+1) == *(p+2)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
            break;
        case 5:
            if(*(p+0) == *(p+4) && *(p+1) == *(p+3)){
                printf("yes\n");
            } else{
                printf("no\n");
            }
            break;
        }
        count = 0;
    }
}