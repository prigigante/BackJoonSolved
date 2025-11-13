#include <stdio.h>

int returnDigit(int a);
int returnDivSum(int a, int b);

int main(void){
    //분해합 문제
    // 각 자리를 더한 값을 어떤 자연수의 분해함.
    //해당 분해합을 만들 수 있는 자연수는 생성자
    // 최소의 생성자를 만드는 프로그램 ==> 1부터 비교하면 될듯?
    int input =0, div_sum =0, digit =0, count = 1, tf = 0;
    scanf("%d" , &input);
    // digit = returnDigit(input);
    // printf("digit >>> %d\n", digit);
    // div_sum = returnDivSum(input, digit);
    // printf("div_sum >>>> %d", div_sum);
    

    while(1){
        digit = returnDigit(count);
        div_sum = returnDivSum(count, digit);
        if(count == input){
            break;
        }
        if(div_sum == input){
            tf =1;
            break;
        }
        count++;
    }
    if(tf){
        printf("%d", count);
    }else{
        printf("0");
    }


}

int returnDigit(int number){
    int return_value = 1;
    if(number <10){
        return return_value;
    }else{
        while(1){
            return_value++;
            number = number/ 10;
            if(number < 10){
                break;
            }
        }
    }
    return return_value;
}
int returnDivSum(int number, int digit){
    int div_sum = number;
    for(int i=0; i<digit; i++){
        div_sum =  div_sum + (number % 10);
        number = number / 10;
    }
    return div_sum;
}