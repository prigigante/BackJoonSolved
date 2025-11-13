#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _p10814Struct
{
    int age;
    char name[101];
}MemberShip;


int main(void){
    short number_of_member =0;
    int age_count[201] = {0,};

    scanf("%hd", &number_of_member);
    // MemberShip* msp = NULL;  
    // msp = (MemberShip*) malloc(sizeof(MemberShip) * number_of_member);
    MemberShip M[number_of_member];
    
    for(short loop = 0; loop < number_of_member; loop++){
        scanf("%d %s", &M[loop].age, &M[loop].name);
        age_count[M[loop].age]++;
    }
    // for(short loop = 0; loop < number_of_member; loop++){ // short 면 문제가 생김
    //     scanf("%d %s", &M[loop].age, &M[loop].name);
    //     age_count[M[loop].age]++;
    // }

    for(int i =1; i < 201; i++){ 
        if(age_count[i] != 0){
            for(int j = 0; j< number_of_member; j++){
                if(M[j].age == i){
                    printf("%d %s\n",M[j].age, M[j].name);
                }
            }
        }
    }
    // for(short loop = 0; loop < number_of_member; loop++){
    //     scanf("%d %s", &temp_age, (msp + loop) -> name);
    //     (msp + loop) -> age = temp_age;
    //     age_count[temp_age]++;
    // }

    // for(int i =1; i < 201; i++){ 
    //     if(!age_count[i]){
    //         continue;
    //     }else{
    //         for(int j = 0; j< number_of_member; j++){
    //             if((msp + j)-> age == i){
    //                 printf("%d %s\n", (msp+j)->age, (msp + j) ->name);
    //             }
    //         }
    //     }
    // }

    return 0;
}