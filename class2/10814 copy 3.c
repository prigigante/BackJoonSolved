#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _p10814Struct
{
    int age;
    char name[101];
}MemberShip;


int main(void){
    int number_of_member =0, temp_age =0;
    // char name_buff[101] = {0,};

    MemberShip* msp = NULL;
    int age_count[201] = {0,};
    // short* age_count_dptr[201] = {NULL, };

    scanf("%d", &number_of_member);
    msp = (MemberShip*) malloc(sizeof(MemberShip) * number_of_member);  

    for(int loop = 0; loop < number_of_member; loop++){
        scanf("%d %s", &temp_age, (msp + loop) -> name);
        // printf("input: age, name >>>> %hd, %s\n", temp_age, name_buff);
        // getchar();

        (msp + loop) -> age = temp_age;

        // (msp + loop) -> name = (char*) malloc(sizeof(char) * (strlen(name_buff) + 1));
        // strcpy((msp + loop) -> name, name_buff);
        // 위의 2줄 문제 사유 -> gets 가 아니라 scanf()는 남는 부분을 잘 할당시키진 아니함
        
        // printf("%hd, %s <<<< msp's age, name\n", (msp + loop) -> age, (msp + loop) -> name);


        age_count[temp_age]++;
        // printf("%d <<<  dptr size\n", sizeof(age_count_dptr[0]));

        //for realloc
        // if(age_count[temp_age] == 1){
        //     age_count_dptr[temp_age] = malloc(sizeof(short) * 1);
        //     *(age_count_dptr[temp_age] + (age_count[temp_age] -1)) = loop;
        //     // *age_count_dptr[age_count[temp_age] -1] = temp_age;
        // }else{
        //     age_count_dptr[temp_age] = realloc(age_count_dptr[temp_age], sizeof(short) * age_count[temp_age]);
        //     // *age_count_dptr[age_count[temp_age] -1] = temp_age; // fale syntex
        //     *(age_count_dptr[temp_age] + (age_count[temp_age] -1)) = loop;
        // }
        

        // *(age_count_dptr + temp_age) = (short*) realloc(*(age_count_dptr + temp_age), sizeof(MemberShip) *age_count[temp_age]);
        // *(*(age_count_dptr + (age_count[temp_age]-1))) = loop;  
        // printf("%hd <<< dptr test\n", *(*(age_count_dptr + (age_count[temp_age]-1))));
    }

    for(int i =1; i < 201; i++){ 
        if(!age_count[i]){
            continue;
        }else{
            for(int j = 0; j< number_of_member; j++){
                if((msp + j)-> age == i){
                    printf("%d %s\n", (msp+j)->age, (msp + j) ->name);
                }
            }
        }
    }

    // for(int i =0; i < 5; i++){
    //     printf("%hd %s <<< age, name\n", (msp + i)->age, (msp + i) -> name);
    // }
    


    // printf("===============\n");
    //realloc print
    // for(int i =1; i < 201; i++){
    //     if(!age_count[i]){
    //         continue;
    //     }else{
    //         for(int print_loop =0; print_loop < age_count[i]; print_loop++){
    //             printf("%hd %s\n", (msp + *(age_count_dptr[i] + print_loop)) -> age, 
    //             (msp + *(age_count_dptr[i] + print_loop)) -> name);
    //         }
    //     }
        
    // }
    

    // for(short age_loop = 1; age_loop < 201; age_loop++){
    //     if(age_count[age_loop]){
    //         for(short print_loop = 0; print_loop < age_count[age_loop]; print_loop++){
    //             for(int i =0; i < number_of_member; i++){

    //             }
    //         }
    //     }
    // }
    // printf("Program End\n");
    return 0;
}