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
    int total_case =0, queue_size =0, input_temp =0, biggest_level =0, now_level =0, target_index =0, target_level =0, now_index = 0, print_counter =0;
    int* my_queue =NULL;
    int level_array[10] = {0,};
    level_array[0] = -1;
    scanf("%d", &total_case);

    for(int case_loop =0; case_loop < total_case; case_loop++){
        scanf("%d %d", &queue_size, &target_index);
        my_queue = (int*) malloc(sizeof(int) * queue_size);

        for(int get_queue_element_loop = 0; get_queue_element_loop < queue_size; get_queue_element_loop++){
            scanf("%d", &input_temp);
            *(my_queue + get_queue_element_loop) = input_temp;
            level_array[input_temp]++;

        }

        target_level =  *(my_queue + target_index);

        biggest_level = 0;
        for(int find_biggest_number_loop =1; find_biggest_number_loop <10; find_biggest_number_loop++){
            if(level_array[find_biggest_number_loop] != 0){
                biggest_level = find_biggest_number_loop;
            }
        }
        now_index = 0;
        print_counter =0;
        while(1){
            now_level = *(my_queue + now_index);

            //skip
            if(now_level == -1){
                now_index++;
                if(now_index >= queue_size){
                    now_index = 0;
                }
                continue;
            }
            //print data
            if(now_level >= biggest_level){
                print_counter++;
                //need to print
                if(now_index == target_index){
                    //now print_counter == answer
                    printf("%d\n", print_counter);
                    break;
                }
                // printf("%d <<< %d's printf\n",now_level, print_counter );

                *(my_queue + now_index) = -1;
                level_array[now_level]--;

                //find new biggest level
                if(level_array[now_level] == 0){
                    
                    for(int i = now_level; i > 0; i--){
                        if(level_array[i] != 0){
                            biggest_level = i;
                            break;;
                        }
                    }
                }
            }else{
                //goto back
                now_index++;
                if(now_index >= queue_size){
                    now_index = 0;
                }
                continue;
            }
        }

        biggest_level =0, now_index =0, target_index =0, target_level =0, now_level =0, queue_size =0, input_temp =0, print_counter =0;
        for(int i =1; i < 10; i++){
            level_array[i] = 0;
        }
    }
}   