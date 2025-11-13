#include <stdio.h>
#include <stdlib.h>

/*
스택수열:
문제: 스택구조로 주어진 수열을 구현 가능한지 판단하고
가능하면 과정 표시, 안되면 NO
단 스택의 push는 오름차순만 허용


스택을 활용한다 ==> 수열은 반드시 내림차순이 기본이며
중간에 커지는 숫자는 push를 느리게 하는 방식으로 구현 

즉, 기본적으로는
스택은 push -> pop의 형태이므로
오름차순 순서만 push를 허용한다 하였으므로, pop은 기본적으로 내림차순의 순서를 가짐
단, 이 떄, 중간에 커지는 경우는 반드시 push를 중단하고 선 pop을 진행하는 방식으로 구현해야 하므로, 
즉, pop이 한번 진행되었다면, 그 pop이 처음 진행 된 맨 처음 수보다 큰 수가 나와야 새로 push가 가능한 상태가 보장되므로
이를 고려하여야 할 듯

e.g.)
4
3
6
가능 : 사유, 맨 처음 pop이 시작된 순서의 첫 숫자는 '4'이므로 '6'보다 작기 때문에 숫자가 커지는 방향으로
출력이 가능

5
3
4
불가능: 사유; 맨 처음 pop이 시작되는 숫자가 '5'이므로 5 -> 3으로 줄어드는 방향의 흐름이 생김
이때 4는 3보다 커지게 되는데, 이 감소추세가 시작된 첫 숫자가 '5'이므로
'5' > '4' 이기 때문에 '4'는 절대로 해당 위치에 올 수 없음
더 자세히
사실 위에서 4가 소진되었다면 가능하겠지만
해당 예시의 전체 순서는
1
2
5
3
4
의 순서이다
만일 
1
2
4
5
3
이라면 가능하겠지만
위에서 4가 소진되지 아니하였으므로,
현재 스택에는 반드시 '3'이 pop되기 전, '4'가 pop이 되어야함이 보장되어야 한다.


잠만 그럼 스택관점에서 보는게 좀더 구현이 편할듯?
위의 조건을 약간 뒤집으면
현재 스택-탑값을 기준으로, 만들어야 하는 수열의 숫자가 스택-탑 보다 크거나 같아야지만 가능 => 작으면 pop을 해야하는데, 그럼 다른숫자가 pop되는것임
*/
int main(void){
    int max_number = 0, temp_input = 0, is_down_stream = 0, down_stream_start_number = 0, now_array_index = 0, push_ready_number = 0, stack_top_index = 0, print_counter = 0;
    int now_array_number =0, now_stack_top_number =0;
    int* array = NULL, *stack = NULL;
    char* answer_array = NULL;
    scanf("%d", &max_number);
    array = (int*) malloc(sizeof(int) * max_number);
    stack = (int*) malloc(sizeof(int) * max_number);
    answer_array = (char*) malloc(sizeof(char) * (max_number*2));
    for(int i =0; i < max_number; i++){
        scanf("%d", &temp_input);
        *(array + i) = temp_input;
    }

    now_array_index = 0, push_ready_number = 1, is_down_stream =0, down_stream_start_number =0, stack_top_index =0;
    now_array_number =0, now_stack_top_number =0;
    int answer_index = 0, is_printf = 0;;

    push_ready_number = 1;
    *(stack + stack_top_index) = push_ready_number;
    push_ready_number++;
    // printf("+\n");
    *(answer_array + answer_index) = '+';
    answer_index++;
    now_stack_top_number = *(stack + stack_top_index);



    while(1){
        //틀리는 상황 ==> 출력이 내림차순만 보장되면 되나
        //중간에 커지는 상황이 불가능하게 이루어지면 중단
        now_array_number = *(array + now_array_index);
        if(now_array_number == now_stack_top_number){
            //need POP
            // printf("-\n");
            *(answer_array + answer_index) = '-';
            answer_index++;

            stack_top_index--;
            now_stack_top_number = *(stack + stack_top_index);
            
            //new target allocate
            now_array_index++;
            if(now_array_index == max_number){
                break;
            }

        }else if(now_array_number > now_stack_top_number){
            //need PUSH
            while(now_array_number > push_ready_number){
                stack_top_index++;
                *(stack + stack_top_index) = push_ready_number;
                push_ready_number++;
                // printf("+\n");
                *(answer_array + answer_index) = '+';
                answer_index++;
            }
            stack_top_index++;
            *(stack + stack_top_index) = push_ready_number;
            push_ready_number++;
            // printf("+\n");
            *(answer_array + answer_index) = '+';
            answer_index++;
            now_stack_top_number = *(stack + stack_top_index);
        }else{
            //mean; now_array_number < now_stack_top_number
            //impossible
            // printf("NO\n");
            is_printf = 1;
            break;
        }
    } 
    if(is_printf ){
        printf("NO\n");
    }else{
        for(int i =0; i < answer_index; i++){
            printf("%c\n", *(answer_array + i));
        }
    }
    return 0;
}
