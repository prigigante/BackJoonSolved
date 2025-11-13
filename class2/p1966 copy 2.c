#include <stdio.h>
#include <stdlib.h>


//이거 그냥 배열보다는 연결리스트때리는게 나을듯? 놉 이거 그렇게 순회하는거 아닌듯
/*
우선순위가 존재하므로, 가장 높은 우선순위를 제외하면 모든 배열은 그대로 유지된다(고대로 복사해서 뒷꽁무니에 박아넣는다고생각하면 편함)
즉 1 3 4 9 7 6 9 8 1
을 기준
가장 높은 우선순위 9기준으로 보면
1 2 3 "9" 7 6 "9" 8 1
여기서 ""제외하고 그대로 다시 뒤에 붙는다 ==> 즉 형태가 고대로 유지됨
따라서 정답은 내가 원하는 타겟의 우선순위보다 높은건 전부 한번에 빼버리고
내 타켓이 동레벨의 몇번째에 해당하는지만 알면 될 듯
단
예를들어 목표 레벨이 2인경우
2 2 2 2 2 "2(목표)" 2 4 2 2
이런식이면
단순 계산이면 6번째(5번인덱스)이지만 실질적으로는 4가 사리지고, 바로 뒤의 2개가 먼저 출력되어야 하므로
이는 추가 비교가 필요할 듯 


같은 레벨중 나보다 뒤에있느 놈들 중!, 나와 차이가 가장 적으면서 가장 뒤에 있는 상위 레벨의 뒤는 나보다 먼저 나감
놉 다른 상위 레벨에서도 이와같은 현상이 일어날 수 있으므로
그것도 전부 고려해야함
정확한 반례 예시
input:
1
6 3
9 8 9 7 8 7
output: 6
answer: 5
이거하면 틀리게 6나옴
이유=> 두개의 8중 뒤의 8이 먼저 날아가기 때문에(앞의 8은 바로 뒤의 9때문에 뒷순서로 밀림) 문제가 생긴다
*/

int main(void){
    int total_test_size =0, queue_size =0, front =0, back =0, temp_input =0, target_index = 0, biggest_level = 0, target_level = 0;
    int same_but_first_back_of_target = 0, smallest_gap_level = 100;
    int same_level_inforntof_target = 0, temp_sum = 0;
    int* my_queue = NULL;
    int level_array[10] = {0,};
    int* answer = NULL;
    int answer_count =0;
    level_array[0] = -1;

    //total case size accept
    scanf("%d", &total_test_size);
    answer = (int*) malloc(sizeof(int )* total_test_size);

    // printf("111\n");
    for(int total_loop = 0; total_loop < total_test_size; total_loop++){
        scanf("%d %d", &queue_size, &target_index);
        my_queue = (int*) malloc(sizeof(int) * queue_size);
        for(int input_loop = 0; input_loop < queue_size; input_loop++){
            scanf("%d", &temp_input);
            //temp_input == level
            // printf("222-1\n");
            level_array[temp_input] = level_array[temp_input] + 1;
            *(my_queue + input_loop) = temp_input;
        }
        target_level = *(my_queue + target_index);
        // printf("222\n");
        for(int i =1; i < 10; i++){
            if(level_array[i]  != 0){
                biggest_level = i;
            } 
        }
        if(biggest_level == 0){
            printf("error biggest level zero\n");
            return 1;
        }
        //같은 레벨 중 어느것이 나보다 먼저 나갈 수 있는 개수인지 확인
        if(target_index + 1 < queue_size){
            for(int i = target_index+1; i < queue_size; i++){
                
                // printf("%d <<<< back index\n", i);
                // printf("%d <<< level\n", *(my_queue + i));
                if(*(my_queue + i) > target_level && *(my_queue + i) <= smallest_gap_level){
                    smallest_gap_level = *(my_queue + i);
                    same_but_first_back_of_target = 0;
                }else if(*(my_queue + i) == target_level){
                    // printf("%d <<<< back index\n", i);
                    same_but_first_back_of_target++;
                }
            }
        }

        // if(smallest_gap_level > 10){
            
        // }
        for(int i =0 ; i < target_index; i++){
            if(*(my_queue + i) == target_level){
                same_level_inforntof_target++;
            }
        }
        //  printf("333\n");
        for(int i = 9; i > target_level; i--){
            // printf("%d <<< level\n", i);
            temp_sum = temp_sum + level_array[i];
        }
        // for(int i =1; i <=9; i++){
        //     printf(">>> level's count %d\n", level_array[i]);
        // }
        // printf("bakc == %d fornt == %d\n", same_but_first_back_of_target, same_level_inforntof_target);
        temp_sum = temp_sum + same_but_first_back_of_target + same_level_inforntof_target;
        temp_sum++;
        // printf("%d\n", temp_sum);
        *(answer + answer_count) = temp_sum;
        answer_count++;
        for(int i =1; i <10; i++){
            level_array[i] = 0;
        }
        free(my_queue);
        target_index =0, biggest_level =0, target_level =0, temp_sum =0, temp_input =0, same_but_first_back_of_target =0, same_level_inforntof_target =0, smallest_gap_level = 100;
    }
    for(int i=0; i < total_test_size; i++){
        printf("%d\n", *(answer+i));
    }
}   