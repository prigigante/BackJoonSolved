#include <stdio.h>
#include <math.h>


int main(void){
    int input_min = 0, input_max = 0, condition = 0;
    scanf("%d %d", &input_min, &input_max);
   
    int sq = sqrt(input_max);
    // printf("%d\n", input_max);
    // printf("%d\n", (int)sqrt(input_max));

    for(int i= input_min; i< input_max; i++){
        for(int j = 2; j <= sq; j++){
            printf("ddd");
            if(i % j == 0){
                if(j == i){
                    break;
                }
                condition = 1;
                break;
            }
        }
        if(!condition){
            printf("%d\n",i);
        }else{
            condition = 0;
        }
    }
    return 0; 







//     int input_min = 0, input_max = 0, condition = 1;
    
    
//     scanf("%d %d", &input_min, &input_max);

//     for(int i = input_min; i < input_max; i++){
//         for(int j  = 2; j < i; j++){
//             if(i % j ==0){
//                 condition = 0;
//                 break;
//             }
//         }
//         if(condition){
//             printf("%d\n", i);
//         }else{
//             condition =1;
//         }
//     }
//     return 0;
}
