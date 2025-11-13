#include <stdio.h>
#include <stdlib.h>


//이거 그냥 배열보다는 연결리스트때리는게 나을듯?

int main(void){
    int front = 0, back = 0, total_case_size = 0, queue_size = 0, target_location =0, target_level = 0, counter = 0, biggest = 0, temp =0;
    // 큐의 맨 앞, 뒤, 총케이스, 개별케이스의 문서개수, 목표의 처음 위치
    //처음은 인덱스 0번임, ==> 4개크기 (마지막 인덱스는 4-1)
    int* my_queue = NULL;
    int* level_counter = NULL;
    level_counter = (int*) malloc(sizeof(int) * 10);
    for(int i =0; i < 10; i++){
        *(level_counter + i) =0;
    }
    scanf("%d", &total_case_size);

    for(int i =0; i <total_case_size; i++){
        scanf("%d %d", &queue_size, &target_location);
        my_queue = (int*) malloc(sizeof(int) * queue_size);
        //로케이션은 들어온 값을 그대로 인덱스로 활용가능
        for(int j =0; j < queue_size; j++){
            scanf("%d", &temp);
            //temp ==> level
            *(my_queue + j) = temp;
            (*(level_counter + temp))++;
        }
        // for(int j =0; j < queue_size; j++){
        //     printf("%d", *(my_queue + j));
        // }
        target_level = *(my_queue + target_location);
        counter = 1;
        for(int j=0; j<queue_size; j++){
            if(*(level_counter + j) != 0){
                biggest = j;
            }
        }

        if(biggest == 0){
            printf("error biggest 0");
            return 1;
        }


        while (1)
        {
            if(target_level == 0){
                printf("%d", counter);
                break;
            }


        }
        
    }

}   