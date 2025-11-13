#include <stdio.h>

int isDigit(char * a);
int toDigit(char * a);

int main(void){
    char string[3][9] = {0,};
    int number = 0;
    gets(string[0]);
    gets(string[1]);
    gets(string[2]);

    // printf("%s\n",string[0] );
    // printf("%s\n",string[1]);
    // printf("%s\n",string[2]);
    

    // for(int i =0; i<3;i++){
    //     printf("%d <<< isDigit()\n", isDigit(string[i]));
    // } // array to pointer, Test

    // for(int i =0; i<3;i++){
    //     if(isDigit(string[i])){
    //         printf("%d <<< toDigit()\n", toDigit(string[i]));
    //     }
    // }
    for(int i =0; i<3; i++){
        if(isDigit(string[i])){
            number = toDigit(string[i]) + (3-i);
            break;
        }
    }
    // printf("%d <<< the answer\n", number);
    
    if(number % 3 == 0){
        if(number % 5 ==0){
            printf("FizzBuzz");
        }else{
            printf("Fizz");
        }
    } else{
        if(number % 5 == 0){
            printf("Buzz");
        }else{
            printf("%d", number);
        }
    }
    return 0;

    // for(int i =0; i<3; i++){
    //     if(isDigit(string[i])){
    //         number = 
    //     }
    // }
    
    // printf("%s\n", array1);
    // printf("%s\n", array2);
    // printf("%s\n", array2);
}


int isDigit(char* string){
    if(*(string + 0) > 57){
        //mean is alphabet
        return 0;
    }else{
        return 1;
    }
}

int toDigit(char * string){
    int count = 0, ten = 1;
    int rv = 0;
    while(*(string + count)){
        count++;
    }
    // printf("%d <<< is the numberSize\n", count);
    //(*(string + i) - 48) is digit
    for(int i = count-1; i>-1; i--){
        // printf("%d <<< is *(string + i)\n", *(string + i));
        // printf("%d <<< is string-48\n", *(string + i) - 47);
        rv = rv + ((*(string + i) - 48) * ten );
        // printf("%d <<< is rv = rv + <<<\n",rv);
        ten = ten * 10;
    }
    return rv;
}