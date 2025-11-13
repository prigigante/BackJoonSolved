#include <stdio.h>

int returnLevel(int a);

int main(void){
    // 벌집 육각형, 각 단계마다 각변의 개수는 총 단계의 수와 동일,
    // 다만 꼭짓점 6개는 각 한번씩 겹친다.
    // 6n-6개의 개수
    int input = 0, rv = 0;
    scanf("%d", &input);

    rv = returnLevel(input);

    printf("%d", rv);
    return 0;
}

int returnLevel(int input){
    int level =1, contain_number =1;
    if(input == 1){ //mean, input == 1
        return 1;
    }    
    while(1){
        level++;
        contain_number = contain_number + 6*level -6;
        if(input <= contain_number){
            return level;
        }
    }
}

