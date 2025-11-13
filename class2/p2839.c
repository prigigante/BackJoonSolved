//최적의 해를 찾는 문제
//가장 적은 봉지개수를 이용하는 문제
//봉지는 각 5 3 키로
// 첫줄에 N kg 입력
//다음에 출력(불가능시 -1)

#include <stdio.h>

int main(void){
    int input = 0, temp = 0, answer = 0, maximun_loop = 0;
    const int three = 3;
    const int five = 5;
    scanf("%d", &input);
    //5kg 봉지가 쵀대개수부터 ~ 0까지 해도 안됨? ==> 못푸는 문제임
    maximun_loop = input / five;
    if(input % five == 0){
        //

        printf("%d", maximun_loop);
        return 0;

    }else if(input % five == 3){
        //

        printf("%d", maximun_loop + 1);
        return 0;
    }

    //나머지가 0은아니고 3도 아님 //걍 한번더 검사해
    for(maximun_loop; maximun_loop >=0; maximun_loop--){
        temp = input - (five * maximun_loop);
        if(temp % three == 0){
            printf("%d",maximun_loop + (temp / three ));
            return 0;
        }
    }
    printf("-1");
    return 0;
}