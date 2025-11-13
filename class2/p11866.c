// 1 2 3 4 5 6 7 
// 1 2 3
// 1 2 4 5 6 7
// 1 2 4
// 1 2 


// 1 2 3 4 5 6 7 
// 1 2 d 4 5 6 7 // d3
// 4 5 6 7 1 2
// 4 5 d 7 1 2 //d6
// 7 1 2 4 5
// 7 1 d 4 5 // d2
// 4 5 7 1
// 4 5 d 1 //d7
// 1 4 5
// 1 4 d // d5
// 1 4 1
// 1 4 d //d1
// 4
// 4 4 4
// 4 4 d //d4

//del sequence => 3 6 2 7 5 1 4


#include <stdio.h>
#include <stdlib.h>

typedef struct _p11866 {
    int number;
    struct _p11866* next;
}Node;

int main(void){
    int max_number = 0, delete_gap = 0, queue_counter = 0;
    
    Node* head = NULL, *temp =NULL, *tail = NULL;

    scanf("%d %d", &max_number, &delete_gap);

    queue_counter = max_number;

    head = (Node*) malloc(sizeof(Node));
    head -> number = 1;
    head -> next = NULL;
    tail = head;
    for(int i =2; i<=max_number; i++){
        temp = (Node*) malloc(sizeof(Node));
        temp -> number = i;
        temp -> next = NULL;
        tail -> next = temp;
        tail = tail->next;
    }
    tail ->next = head;
    temp = tail;    
    printf("<");

    while(queue_counter > 0){
        for(int i = 0; i < delete_gap; i++){
            tail = temp;
            temp = temp ->next;
        }// now temp is target
        queue_counter = queue_counter - 1;
        tail -> next = temp -> next;

        if(queue_counter == 0){
            printf("%d", temp->number);
            break;
        }else{
            printf("%d, ", temp->number);
            free(temp);
            temp = tail;
        }
    }
    printf(">");
    return 0;

}