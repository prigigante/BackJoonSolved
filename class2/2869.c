//달팽이 *** 잘 못품 사실상, 질문게시판 보고 푼거임
/*
높이가 v나무 올라감
낮에 A미터 올라
밤에 B미터 미끄러
정상 => 안미끌

달팽이 나무막대 모두 올라갈라면 몇일
A B V가 각 공백 구분

*/
#include <stdio.h>
//첫번째 날 이후는 A-B만큼

int main(void){
    int A =0, B=0, V=0, start =0, day = 0;
    scanf("%d %d %d", &A, &B, &V);
    int gap = A-B;
    if(A==V){
        printf("1");
    }else{
        V = V - A;
        day = V/gap + 1;
        if(V%gap == 0){ //굳이 반목문 + 비교문을 쓰지 말고, 한번에 얻을수 있는 경우는 수학적으로 한번에 해결할 것
            printf("%d", day);
        }else{
            printf("%d", day + 1);
        }
    }
    return 0;
}
//첫번째 날 이후는 A-B만큼
// int main(void){
//     int A =0, B=0, V=0, start =0, day = 0;
//     scanf("%d %d %d", &A, &B, &V);
//     int gap = A-B;

    
//     //day1
//     if(A==V){
//         printf("1");
//     }else{
//         while(1){
//             if(A + gap*day++ >= V){
//                 printf("%d",day);
//                 break;
//             }
//         }
//     }
//     return 0;
// }
//시간 제한 초과
// int main(void){
//     int A =0, B=0, V=0, start =0, day = 1;
//     scanf("%d %d %d", &A, &B, &V);
//     while(1){
//         start = start + A;
//         if(start >= V){
//             break;
//         }
//         start = start -B;
//         day++;
//     }
//     printf("%d", day);
//     return 0;
// }