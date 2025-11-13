#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isLongerString(char** string, int index);
int isForeString(char** string, int index);

int main(void){ // 목적, 긴 문자열을 뒤로, ,, 만약 길이가 같다면 사전상 나중에 오는 문자열을 뒤로
// 즉 , 길고 나중에 오는 문자열을 뒤로 보내면 됨
    char buff[51] = {0,};
    int test_case = 0;
    int temp_int =0;
    char ** string_array = NULL;

    char* tmep_string = NULL;


    scanf("%d", &test_case);
    string_array = (char **) malloc(sizeof(char*) * test_case);
    getchar();
    for(int i =0; i < test_case; i++){
        // printf("input __ loop count >>> %d\n", i);
        gets(buff);
        *(string_array + i) = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(*(string_array + i), buff);
    }

    for(int i =0; i<test_case-1; i++){
        for(int j =0; j<test_case-1-i; j++){
            temp_int = isLongerString(string_array, j);
            if(temp_int > 0){
                tmep_string = *(string_array + j + 1);
                *(string_array + j + 1) = *(string_array + j);
                *(string_array + j) = tmep_string;
            }else if(temp_int ==0){
                temp_int = isForeString(string_array, j);
                if(temp_int > 0){
                    tmep_string = *(string_array + j + 1);
                    *(string_array + j + 1) = *(string_array + j);
                    *(string_array + j) = tmep_string;
                }else{
                    continue;
                }
            }else{
                continue;
            }
        }
    }
    printf("%s\n", *(string_array));
    for(int i =1; i < test_case; i++){ //input correctness test
        // printf("output __ loop count >>>> %d\n", i);
        if(isLongerString(string_array, i-1)== 0){
            if(isForeString(string_array, i-1) == 0){
                continue;
            }
        }
        printf("%s\n", *(string_array + i));
    }
    // printf("\nprogram end\n");
    return 0;
}


int isLongerString(char** string_array, int index){
    return strlen(*(string_array + index)) - strlen(*(string_array + index + 1)); 
} // mean  0 ==> same, 0>return ==> fore is longer, 0<return ==> last is longer

int isForeString(char** string_array, int index){
    int len = strlen(*(string_array + index));
    int rv = 0, alphabet_index = 0;
    while( *(*(string_array + index) + alphabet_index) )
    {
        rv = *(*(string_array + index) + alphabet_index) 
        - *(*(string_array + (index + 1)) + alphabet_index);
        if(rv == 0){
            alphabet_index++;
            continue;
        }else{
            return rv;
        }
    }
    return rv;  
}// mean  return == 0 => same, return > 0 => index is not fore, return < 0 => index is fore
//0이면 같은문자열, 0보다 크면 index가 나중에 오는놈, 0보다 작으면 index가 먼저 오는놈