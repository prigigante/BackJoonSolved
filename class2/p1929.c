//이거 쥰내 힘들었음 정확히 에라스토스테네스의 채 문제인데 
//이걸 모르면 무조건 시간 터진다.

#include <stdio.h>
#include <math.h>

int array[1000001] = {0,};

int main(void){
    int min =0, max = 0;
    double sqrt_value = 0;
    int int_sqrt_value = 0;
    scanf("%d %d", &min, &max);

    sqrt_value = sqrt(((double) max));
    int_sqrt_value = (int) (round(sqrt_value));
    // 2 3 5 7 이 4개만 중접으로 조지면 될듯한데
    int mult = 2;
    for(int i =2; i <= int_sqrt_value; i++){
        while(1){
            if(mult * i > max){
                //탈출조건
                break;
            }
            array[mult * i] = 1;
            mult++;
        }
        mult = 2;
    }

    array[0] = 1, array[1] = 1;
    //바로 위의 한줄(아마도 array[1] = 1) 추가 안하면 뻑날 수 잇음(만약 min값이 1로 들어오는 경우)


    for(int i = min; i <= max; i++){
        if(array[i] == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}