#include <stdio.h>
#include <stdlib.h>

#define A 1234567891

int main(void){ // 소문자 는 아스키 코드가 a >> 97임
    unsigned long long int demension = 1, temp = 0;
    int case_size =0;
    char buff[51] = {0,};
    unsigned long long int rv = 0;
    scanf("%d", &case_size);
    // getchar();
    // gets(buff);
    scanf("%s", buff);

    for(int i=0; i<case_size; i++){
        // demension = demension%A;
        temp = (buff[i]-96)*demension;
        temp = temp % A;
        rv = rv + temp;
        demension = demension * 31;
        rv = rv%A;
    }


    
    rv = rv % A;

    printf("%llu", rv);
    return 0;
}