/**
 * 일단 괄호 개수가 전부 일치해야 함
 * 무조건 오른쪽 괄호는 왼쪽 괄호가 존재 => 왼쪽이 많을 순 있긴함
 * 무조건 1:1매칭
 * 괄호가 짝을 이룬 상태라면, 해당 괄호 속에서는 무조건 짝이 맞는 상태여야함
 * 문자열 마지막은 온점이고, 문제가 끝나는 신호는 아무것도 없이 온점 하나만 온다.
 */



 // 여러번 틀린 이유
 /**
  * 0) sp 초기화 안해줌(라인별로)
  * 1) 마지막 sp 검사 안함
  * 2) 닫힌 괄호 검사시 sp 가음수인 경우 검사 안함
  */
#include <stdio.h>




int main(void){
    char string[102] = {0}, before_parentheses = '{', now_char = 0;
    int left_count = 0, right_count = 0, now_index = 0, state = 0;
    char stack[50] = {0,}, sp = -1;

    while(1){
        fgets(string, 102, stdin);
        //읽는 문자열 100, 널 1개, +개행1개?
        if(string[0] == '.'){
            break;
        }
        now_index = 0, left_count =0, right_count =0, now_char = 0, state = 1, sp = -1;
        now_char = string[now_index];
        while(now_char != '.'){
            now_char = string[now_index];

            if(now_char == '('){
                left_count++;
                sp++;
                if(sp > 49){
                    state = 0;
                    break;
                }
                stack[sp] = now_char;
            }else  if(now_char == ')'){
                if(sp < 0 || stack[sp] != '('){
                    state = 0;
                    break;
                }//괄호 어겼는지 확인

                left_count--;
                if(left_count < 0){
                    state = 0;
                    break;
                }
                stack[sp] = 0;
                sp--;
            }else  if(now_char == '['){

                right_count++;
                sp++;
                if(sp > 49){
                    state = 0;
                    break;
                }
                stack[sp] = now_char;
            }else  if(now_char == ']'){

                if(sp <0 || stack[sp] != '['){
                    state = 0;
                    break;
                }

                right_count--;
                if(right_count < 0){
                    state = 0;
                    break;
                }
                stack[sp] = 0;
                sp--;
            }else if(now_char == '.'){
                break;
            }else{

            }
            now_index++;
        }
        if(state == 1 && sp == -1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        for(int i =0; i < 50; i++){
            stack[i] = 0;
        }
    }
    return 0;
}