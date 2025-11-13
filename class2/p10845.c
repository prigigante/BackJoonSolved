#include <stdio.h>
#include <stdlib.h>


typedef struct _p10845 {
    int number;
    struct _p10845* next;
}QueueNode;

int isEmpty(int a);

int main(void){
    int case_size = 0, input_number = 0, array_counter = -1;
    char c = 0, buff[10] = {0,};
    QueueNode* front = NULL, *back = NULL;
    QueueNode* array = NULL;
    QueueNode* tempNode = NULL;

    scanf("%d", &case_size);

    // printf("%d <<< is inputcase\n", case_size);


    for(int loop =0; loop < case_size; loop++){
        scanf("%s", buff);
        // printf("%s <<< input string\n", buff);
        c = buff[0];
        if(c == 'p'){
            // printf("init p \n");
            c = buff[1];
            if(c == 'u'){ // push
                if(array_counter < 0){
                    //init 
                    // printf("init \n");
                    array_counter = array_counter + 1; // mean 0
                    scanf("%d", &input_number);
                    tempNode = (QueueNode*) malloc(sizeof(QueueNode));
                    tempNode -> number = input_number;
                    tempNode -> next =NULL;
                    front = tempNode;
                    back = tempNode;
  
                }else{
                    array_counter = array_counter + 1;
                    scanf("%d", &input_number);
                    tempNode = (QueueNode*) malloc(sizeof(QueueNode));
                    tempNode -> number = input_number;
                    tempNode -> next = NULL;
                    back -> next = tempNode;
                    back = back -> next;
                }

            }else{ //pop
                if(isEmpty(array_counter)){
                    printf("-1\n");
                }else{
                    tempNode = front;
                    front = front ->next;
                    if(front == NULL){
                        back = NULL;
                    }
                    printf("%d\n", (tempNode ->number));
                    free(tempNode);
                    array_counter = array_counter -1;
                }
            }
            
        }else if(c == 's'){ //size
            // printf("init s\n");
            if(isEmpty(array_counter)){
                printf("0\n");
            }else{
                printf("%d\n", array_counter + 1);
            }
        }else if(c == 'e'){ //empty
            // printf("init e\n");
            printf("%d\n",isEmpty(array_counter));
        }else if(c == 'f'){ //front
            if(isEmpty(array_counter)){
                //empty
                printf("-1\n");
            }else{
                printf("%d\n", front ->number);
            }
        }else if(c == 'b'){ //back
            // printf("init b\n");
            if(isEmpty(array_counter)){
                //empty
                printf("-1\n");
            }else{
                printf("%d\n", back ->number);
            }
        }else {
            printf("error\n");
            exit(1);
        }
    }
    return 0;


}

int isEmpty(int a){
    if(a < 0){
        return 1;
    }else{
        return 0;
    }
}
