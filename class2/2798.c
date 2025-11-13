#include <stdio.h>
#include <stdlib.h>


int main(void){
    int number_of_card = 0, limit_number = 0;
    int* array = NULL;
    int max = 0, sum =0;
    scanf("%d %d", &number_of_card, &limit_number);

    
    array = (int*) malloc(sizeof(int) * (number_of_card + 1));

    for(int i =0; i < number_of_card; i++){
        scanf("%d", (array + i));
    }
    // for(int i =0; i < number_of_card; i++){
    //     printf("%d ", *(array + i));
    // }

    for(int loop_one =0; loop_one < number_of_card-2; loop_one++){
        for(int loop_two = loop_one +1; loop_two < number_of_card-1; loop_two++){
            for(int loop_three = loop_two +1; loop_three < number_of_card; loop_three++){
                sum = *(array + loop_one) + *(array + loop_two) + *(array + loop_three);
                if(sum <= limit_number){
                    if(sum > max){
                        max = sum;
                    }
                }
                sum = 0;
            }
        }
    }

    printf("%d", max);
}