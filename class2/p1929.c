//소수찾기 => 머시기 체

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int sqrt_int = 0, now_number =0, max_number =0, min_number =0;;
    double r_sqrt = 0;
    char* array = NULL;
    scanf("%d %d", &min_number, &max_number);
    r_sqrt = sqrt(max_number);
    sqrt_int = ceil(r_sqrt);
    array = (char*) malloc(sizeof(max_number));

    for(int i = min_number; i< max_number; i++){
        now_number = i;
        
    }
}
