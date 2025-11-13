#include <stdio.h>


int main(void){
    char buff[101] = {0,}, stack[50] = {0,};
    int stack_top = -1;
    char* ptr = NULL;

    fgets(buff, 101, stdin);
    ptr = buff;
    if(*ptr == '.'){
        return 0;
    }
    while(1){
        if(*ptr == '('){
            if(stack_top > 49){
                printf("no\n");
                *ptr = ".";
            }
            stack_top++;
            stack[stack_top] = '(';
        }else if(*ptr == ')'){
            if(stack_top < 0){
                printf("no\n");
                *ptr = ".";
            }
            if(stack[stack_top] == '('){
                
            }else{
                printf("no\n");
                *ptr = ".";
            }
        }else if(*ptr == '['){
            if(stack_top > 49){
                printf("no\n");
                *ptr = ".";
            }
            stack_top++;
            stack[stack_top] = '(';
        }else if(*ptr == ']'){
            if(stack_top <0){

            }
            if(stack[stack_top] == '['){
                
            }else{
                printf("no\n");
                *ptr = ".";
            }
        }
        if(*ptr == '.'){
             
        }
    }



}