//해쉬 기법 사용
// N개의 1차 입력(비교군/정답지)
// M개의 2차 입력(비교 대상)
// 처음 입력받은 N개의 배열을 기반으로, 나중에 받은 M개 배열 중
// N개 배열에 이미 존재하는지 찾는 문제
// 모든 입력 중 입력-데이터-타입은 signed int 형식임(개수는 short범위 안에 들어옴)


#include <stdio.h>
#include <stdlib.h>

typedef struct _p1920
{
    int data;
    struct _p1920* next;
}HashNode;

typedef struct _p1920_2{
    HashNode* front;
}Header;

int isThere(Header* header, int index, int data);

int main(void){
    int answer_case_size = 0, problem_case_size = 0, input_temp = 0, temp_div_number, input_temp_index = 0, insert_index = 0;
    const int div_size = 499; //1000-2 = 998 -1 = 997 // -1부터 -498 / 0 / 1부터 498
    int* first_input_array = NULL,* second_input_array = NULL;
    Header* hash_header = NULL;
    //case size 
    scanf("%d", &answer_case_size);
    //memory allocate
    first_input_array = (int*) malloc(sizeof(int) * answer_case_size);

    //hash allocate
    hash_header = (Header*) malloc(sizeof(Header) * 997);
    for(int i =0; i < 996; i++){
        (hash_header+i) -> front = NULL;

    }

    //take info of array
    for(int i = 0; i < answer_case_size; i++){
        scanf("%d", &input_temp);
        //div by 499
        temp_div_number = input_temp % div_size;
        // plus 498
        input_temp_index = temp_div_number + 498;

        insert_index = isThere(hash_header, input_temp_index, input_temp);
        if(insert_index < 0){
            continue;
        }else if(insert_index == 0){
            if(insert_index == 0){
                HashNode* temp_node = (HashNode*) malloc(sizeof(HashNode));
                temp_node -> data = input_temp;
                temp_node -> next = NULL;
                (hash_header + input_temp_index) -> front =temp_node;
                
            }
        }else{
            //need to insert data to hash
            HashNode* temp_node = NULL;
            HashNode* insert_node = NULL;
            temp_node = (hash_header + input_temp_index) -> front;
            for(int i=0; i<insert_index-1; i++){
                temp_node = temp_node -> next;
            }
            insert_node = (HashNode*) malloc(sizeof(HashNode));
            insert_node -> data = input_temp;
            insert_node -> next = NULL;
            temp_node -> next = insert_node;
        }
    }   
    scanf("%d", &problem_case_size);
    for(int i =0; i < problem_case_size; i++){
        scanf("%d", &input_temp);
        //div by 499
        temp_div_number = input_temp % div_size;
        // plus 498
        input_temp_index = temp_div_number + 498;

        insert_index = isThere(hash_header, input_temp_index, input_temp);
        if(insert_index == -500){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}


//find == return -501, first = 
int isThere(Header* hash_header, int index, int data){
    int index_count = 0;
    HashNode* temp_node = NULL;
    temp_node = (hash_header+index) -> front;

    while(temp_node){
        if(temp_node -> data == data){
            return -500;
        }
        temp_node = temp_node -> next;
        index_count++;
    }
    return index_count;
}