#include <stdio.h>


int main(void){
    char buff[101] = {0,}, stack[50] = {0,};
    int small_balance = 0, big_balance =0, answer = 0, stack_top = -1;
    char* ptr = NULL;
    fgets(buff, 101, stdin);

    ptr = buff;
    if(*ptr == '.'){
        return 0;
    }
    /*
    따라서 문제이서는 다음이 보장되어야 함
    1) 어떤 괄호든, 왼쪽 괄호가 먼저 나와야 함

    2) 어떤 괄호든 짝이 서로 보장되어야 함 => 문제 조건으로 보장되긴 하는 듯
    ? 오른쪽 괄호는 왼쪽 괄호가 보장된다고 했지, 왼쪽 괄호가 오른쪽 괄호를 보장한다는 의미는 아닌거같은데
    키포인트인가?

    3) 어떤 괄호든, 짝의 사이에도 균형이 보장되어야 함
    ([ (([( [ ] ) ( ) (( ))] )) ]).
    */

    //스택에서 0은 소괄호를, 1은 대괄호를 의미
    while(1){ 
        switch(*ptr){
            case '(':
                stack_top++;
                if(stack_top > 49){
                    printf("no");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                stack[stack_top] = 0;
                break;
            case ')':
                if(stack_top < 0){
                    printf("no\n");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                if(stack[stack_top] != 0){
                    //즉 꼬인거
                    printf("no\n");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                stack_top--;
                break;
            case '[':
                stack_top++;
                if(stack_top > 49){
                    printf("no\n");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                stack[stack_top] = 1;
                break;
            case ']':
                if(stack_top < 0){
                    printf("no");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                if(stack[stack_top] != 1){
                    //즉 꼬인거
                    printf("no\n");
                    fgets(buff, 101, stdin);
                    ptr = buff;
                    if(*ptr == '.'){
                        break;
                    }
                    continue;
                }
                stack_top--;
                break;
            case '.':
                if(stack_top >= 0 ){
                    printf("no\n");
                    stack_top = -1;
                }else{
                    printf("yes\n");
                    stack_top = -1;
                }
                fgets(buff, 101, stdin);
                ptr = buff;
                if(*ptr == '.'){
                    break;
                }
                continue;
        }
        ptr = ptr + 1;
        // printf("%d\n", ++answer);
    }
    return 0;
}


/* 아래 조건은 단순히 왼쪽괄호 다음 오른쪽 괄호가 보장되는 것을 의미함(괄호 사이 섞이는건 탐지 x)
    while(ptr){
        switch (*ptr)
        {
        case '(':
            small_balance++;
            break;
        case ')':
            small_balance++;
            if( ( (small_left - small_right)  < 0)){

            }

        case '[':
            big_balance++;
        case ']':
            big_balance++;
            if(((big_left - big_right) < 0)){

            }
        default:
            break;
        }
        ptr = ptr + 1;
    }

*/
