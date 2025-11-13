#include <stdio.h>
// *********** 중요 !!!!!!!! ==> 함수를 반드시 사용하는 습관을 들일 것
int facto(int a);

int main(void){
    //이항계수 구하기
    // 공식은 몰라서 공식은 검색해서 참고했음
    /*  n! / k!(n-k)!
    //     */
    // int num1 =0, num2 =0, num3 = 0,np = 1, kp = 1, nkp = 1;
    // int rv = 0;
    // //np for n! , kp for k!, nkp for (n-k)!
    // scanf("%d %d", &num1, &num2);
    // num3 = num1 - num2;
    // if(!num3){
    //     rv = 1;
    // }else{
    //     // printf("not same\n");
    //     for(int i =1; i <= num3; i++){
    //         np = np * i, kp = kp * i, nkp = nkp * i;
    //     }// complete, nkp
    //     // printf("nkp >>>> %d\n",nkp);
    //     for(int i = num3+1; i<=num2; i++){
    //         np = i * np, kp = i * kp;
    //     }// complete, kp
    //     // printf("kp >>>> %d\n", kp);
    //     for(int i = num2+1; i <= num1; i++){
    //         np = i * np;
    //     }
    //     // printf("np >>>>> %d\n",np);
    //     rv = np / (kp*nkp);
    // }
    // printf("%d", rv);
    //위의 공식 다 틀림
    int input1 = 0, input2 =0; 
    scanf("%d %d", &input1, &input2);
    printf("%d", facto(input1) / (facto(input2)*facto(input1-input2)));
    return 0;
}

int facto(int target){
    if(target == 0){
        return 1;
    }
    int rv = 1;
    for(int i =1; i<= target; i++){
        rv = rv * i;
    }
    return rv;

    //
}