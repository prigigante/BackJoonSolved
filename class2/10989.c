#include <stdio.h>

int main(void){ // short 배열은 총 case만큼을 못담는 경우가 생기기 때문에
//즉 인덱스 -> 값으로, 값 -> 인덱스로 변경
// 값의 사이즈는 int 의 범위인데, short배열로 치면 ㅈ댄다.
    int array[10001] = {0,}, temp = 0;
    int case_size = 0;
    
    scanf("%d", &case_size);

    for(int i =0; i<case_size; i++){
        scanf("%hd", &temp);
        array[temp]++;
    }
    
    for(short i =0; i<10001; i++){
        if(array[i] >0){
            for(int j =0; j<array[i]; j++){
                printf("%hd\n", i);
            }
        }
    }
    return 0;
}