// thie file is ver_one, faled.
#include <stdio.h>
char array[1000001] = {0,}; 
int main(void){
    int case_size = 0, temp = 0, case_temp = 0;


    scanf("%d", &case_size);
    for(int i= 0; i < case_size; i++){
        scanf("%d", &temp);
        array[temp]++;
    }
    for(int i=1; i < 1000001; i++){
        if(array[i]){
            printf("%d\n",i);
        }
    }


    // array[3]++;
    // if(array[3]){
    //     printf("true\n");
    // }else{
    //     printf("false\n");
    // }
    return 0;

}