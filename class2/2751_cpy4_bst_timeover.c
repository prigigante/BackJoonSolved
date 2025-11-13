#include <stdio.h>
#include <stdlib.h>

typedef struct p2751_struct
{
    int data;
    struct p2751_struct* left;
    struct p2751_struct* right;
}Node;

struct BST
{
    Node* root;
};


void inOrderPrint(Node* root);

Node* createBstNode(int number);

int main(void){
    int case_size = 0, input = 0;
    struct BST bst;
    Node * temp_node_ptr = NULL;
    scanf("%d", &case_size);
    
    scanf("%d", &input);
    bst.root = createBstNode(input);
    // first input end;

    for(int i =1; i < case_size; i++){
        scanf("%d", &input);
        temp_node_ptr = bst.root;
        while(1){
            if(input > temp_node_ptr -> data){
                if(temp_node_ptr -> right == NULL){
                    temp_node_ptr -> right = createBstNode(input);
                    /*
                    temp_node_ptr -> right = (Node*) malloc(sizeof(Node));
                    temp_node_ptr -> right -> data = input;
                    temp_node_ptr -> right -> right = NULL;
                    temp_node_ptr -> right -> left = NULL;
                    //like this code, also failed
                    */
                    break;
                }else {
                    temp_node_ptr = temp_node_ptr -> right;
                }
            }else{ // input < temp_node_ptr -> data
                if(temp_node_ptr -> left == NULL){
                    temp_node_ptr -> left = createBstNode(input);
                    break;
                }else{
                    temp_node_ptr = temp_node_ptr -> left;
                }
            }
        }
    }

    inOrderPrint(bst.root);

    //printf("program end\n");
    return 0;


}

Node* createBstNode(int number){
    Node* node = NULL;
    node = (Node*) malloc(sizeof(Node));
    node -> data = number;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void inOrderPrint(Node* root){
    if(root != NULL){
        inOrderPrint(root -> left);
        printf("%d\n", root -> data);
        inOrderPrint(root -> right);
    }
}
