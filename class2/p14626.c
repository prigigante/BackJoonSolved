/*
ISBN문제
앞자리부터 1,3,1,3...의 가중치를 곱함
마지막 13번째 자리는 앞의 숫자를 검증용
마지막 13번째 자리의 값은, 해당 값을 더하고 10으로 나누면, 나머지가 0이 되도록 하는 값임
이대 마지막자리 제외, 하나가 손상된 상태로 제공될때, 해당 손상된 숫자를 출력하라
e.g.) input <- 9788968322*73 // output <- 2
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char buff[14] = {0,};
    int answer =-1, loss_index = 0, temp = 0;
    // char ptr;

    fgets(buff, 14, stdin);
    for(int i = 0; i < 13; i ++){
        if(buff[i] == '*'){
            loss_index = i;
            continue;
        }else{
            if((i+1)%2 == 0){
                // mult 3
                // ptr = buff[i];
                // temp = temp + atoi(&ptr)*3;
                // printf("\n%d\n", atoi(&ptr));
                temp = temp + (buff[i] - '0')*3;
                // printf("\n%d\n", buff[i] - '0');
            }else{
                // mult 1
                // ptr = buff[i];
                // temp = temp + atoi(&ptr)*3;
                // 잘못된 방식임, 배열 주소로 해도 틀림(문자열 자체로 조지기 때문에)
                temp = temp +  (buff[i] - '0');
                // printf("\n%d\n", buff[i] - '0');
            }
        }
    }
    if((loss_index+1) % 2 == 0){
        // need to mult 3
        for(int i =0; i < 10; i++){
            if((temp + (i * 3)) % 10 == 0){
                answer = i;
                break;
            }
        }
    }else{
        //need to mult 1
        for(int i =0; i < 10; i++){
            if((temp + i) % 10 == 0){
                // printf("ASDFASDF");
                answer = i;
                break;
            }
        }
    }   
    
    if(answer < 0){
        exit(1);
    }
    printf("%d", answer);
    return 0;
}