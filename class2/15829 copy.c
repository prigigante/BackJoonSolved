#include <stdio.h>
#include <stdlib.h>

unsigned long returnSomeSquare(int i);

int main(void){ // 소문자 는 아스키 코드가 a >> 97임
    char* buff = NULL;
    int string_size =0, index = 0;
    unsigned  long rv = 0;
    unsigned  long sq = 0;
    scanf("%d", &string_size);
    getchar();
    buff = (char*) malloc(sizeof(char) * (string_size +1));
    gets(buff);
    // printf("%s <<< <string \n", buff);
    for(int i=0; i < string_size; i++){
        sq = returnSomeSquare(i);
        // printf("%lld <<< sq\n",sq);
        // printf("%lld <<< sum\n\n", (*(buff + i) - 96) * sq);
        rv = rv + (*(buff + i) - 96) * sq;
    }
    printf("%lu", rv%1234567891);
}

unsigned  long returnSomeSquare(int repeat){
    unsigned long rv = 1;
    // printf("%lld %d <<< rv, repeat\n", rv, repeat);
    for(int i=0; i<repeat; i++){
        // printf("%d <<< repeat\n", repeat);
        // printf("%lld %llu\n",rv, rv);
        rv = rv*31;
        // printf("%lld %llu\n",rv, rv);
    }
    return rv;
}