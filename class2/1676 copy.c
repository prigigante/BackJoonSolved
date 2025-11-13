#include <stdio.h>

int main(void){
    // unsigned long long int facto =1, temp = 0;
    // for(int i = 1; i< 501; i++){
    //     temp = facto;
    //     facto = facto * i;
    //     if(facto < temp){
    //         printf("overFlow\n");
    //         break;
    //     }
    // }
    // printf("%llu\n%llu <<< facto temp", facto, temp);  
    
    // 2 * 5 = 10
    // 조건이 되는 한에서 2랑 5로 전부 나누면서 실행
    // 나중에 조건 검사하고, 총 나눈 2와 5의 개수로 10의 개수를 추론 => 0의 개수
    unsigned long long int facto = 1;
    int div_count_2 =0, div_count_5 = 0, more =0;
    int repeat = 0, temp =0;

    scanf("%d", &repeat);

    for(int i =1; i <= repeat; i++){
        temp = i;
        if(temp % 2 == 0){
            temp = temp / 2;
            div_count_2++;
        }
        if(temp % 5 ==0){
            temp = temp / 5;
            div_count_5++;
        }
        facto = facto * temp;
    }
    while(!facto%10){
        more++;
        facto = facto / 10;
    } // 이 파일은 시간초과 뜸 시발

    if(div_count_2 > 0 && div_count_5 >0){
        if(div_count_2 > div_count_5){
            printf("%d", div_count_5 + more);
        }else{
            printf("%d", div_count_2 + more);
        }
    }else{
        printf("%d", more);
    }

    return 0;
}