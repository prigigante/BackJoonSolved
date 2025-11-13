#include <stdio.h>
#include <stdlib.h>

typedef struct _p2164
{
    int data;
    struct _p2164* next;
}Node;

typedef struct _p2164_2
{
    int count;
    Node* front;
}Head;


int main(void){
    //일단 연결리스트로 구현해보기
    int size = 0, count = 0;
    Head* head = (Head*) malloc(sizeof(Head));
    head -> count = 0;
    head -> front = NULL;

    Node* node = (Node*) malloc(sizeof(Node));
    Node* back = NULL;


    scanf("%d", &size);
    count = size;

    node -> data = 1;
    node -> next = NULL;
    head ->count++;

    head -> front = node;
    back = node;

    if(size > 1){
        for(int i =2; i <= size; i++){
            node -> next = (Node*) malloc(sizeof(Node));
            node = node -> next;
            node ->data = i;
            node ->next = NULL;
            back = node;
            head -> count++;    
            // printf("%d << count\n", head ->count);   
            // printf("%d << node data\n", node -> data);  
        }    
    }
    // printf("\n\n%d <<< back data\n", back->data);

    // node = head -> front;
    // while(node != NULL){
    //     printf("%d ", node -> data);
    //     node = node -> next;
    // }

    int odd = 1;
    while(head -> count >= 2){
        node = head -> front;
        // printf("%d << ",head -> front -> data);
        if(odd % 2){
            // printf("\n%d << count in odd", head ->count);
            head -> front = node -> next;
            // printf("%d << ",head -> front -> data);
            node -> next = NULL;
            free(node);
            head -> count--;
            odd++;
            // printf("\n%d << node data in odd", head->front->data);
            // printf("\n%d << node data in odd", head->front->next ->data);
        }else{
            // printf("\n%d << count in even", head ->count);
            head -> front = node -> next;
            node -> next = NULL;
            back -> next = node;
            back = node;
            odd++;
            // printf("\n%d << node data in even", head->front->data);
            // printf("\n%d << node next data in even ", head->front->next->data);
        }
    }
    printf("%d", head->front->data);
    return 0;
}