#include <stdio.h>
#include <stdlib.h>


typedef struct _p7568{
	int weight;
	int height;
	int rank;
}HumanMass;
// 수정 사항 1
//지속적으로 오류 결과 -> 구조체의 정보룰 unsigned char에서 int로 수정시 정상적으로 처리됨
// ex 맨 마지막정보가 둘 모두 가장 작은 데이터일때 정상적으로 처리가 안되는 현상이 있었음

void giveRank(HumanMass *a, int size);
void reRank(HumanMass *b, int size);


int main(void){
	int number_of_human = 0, temp_weight = 0, temp_height = 0;
	HumanMass * array = NULL;

	scanf("%d", &number_of_human);
	array = (HumanMass*) malloc(sizeof(HumanMass) * number_of_human);


	for(int i =0; i <number_of_human; i++){
		scanf("%d %d", &temp_weight, &temp_height);
		(array + i) -> weight = temp_weight;
		(array + i) -> height = temp_height;
		(array + i) -> rank = 1;
	}
	// for(int i =0; i < number_of_human; i++){
	// 	printf("%d ", (array + i) -> rank);

	// }
	// printf("\n");
	giveRank(array, number_of_human);
	reRank(array, number_of_human);
	for(int i =0; i < number_of_human; i++){
		printf("%d ", (array + i) -> rank);

	}
	return 0;
}

void reRank(HumanMass *array, int size){
	int min = 100, counter = 0;
	HumanMass * temp = NULL;
	int under_bound = -11;
	for(int out_loop =0; out_loop < size; out_loop++){
        min = 100;
		for(int inner_loop =0; inner_loop < size; inner_loop++){
			temp = (array + inner_loop);
            if(temp -> rank > under_bound){
                if( (array + inner_loop) -> rank < min){
                    min = temp -> rank;
                    counter = 1;	
                    //printf("new min allocate >>> %d \n", min);
                }else if((array+inner_loop) -> rank == min){
                    counter = counter + 1;
                    //printf("%d %d <<<is min counter\n", min, counter);
                }	
            }
		}
		for(int i =0; i < size; i++){
			temp = (array + i);
			if(temp -> rank > min){
				if(counter > 1){
					temp -> rank = (temp -> rank) + counter - 1;
				}
			}
		}
		counter = 0;
		under_bound = min;
	}

}


void giveRank(HumanMass *array, int size){
	int big_w =0, big_h =0, small_w = 0, small_h =0;
	HumanMass* big = NULL, *small = NULL;
	for(int big_loop =0; big_loop < size; big_loop++){
		big = (array + big_loop);
		for(int small_loop =0; small_loop < size; small_loop++){
			small = (array + small_loop);
			//mean, same rank
			//need to distint
			big_w = big -> weight;
			big_h = big -> height;
			small_w = small -> weight;
			small_h = small -> height;
			// printf("%d %d %d <<< NOW BIG weight height rank\n", big_w, big_h, big->rank);
			// printf("%d %d %d <<< NOW SML weight height rank\n", small_w, small_h, small->rank);
			if(big_w > small_w && big_h > small_h){
				small -> rank = (big -> rank) + 1;
				// printf("%d %d %d <<< BIG weight height rank\n", big_w, big_h, big->rank);
				// printf("%d %d %d <<< SML weight height rank\n", small_w, small_h, small->rank);
			}else if(small_w > big_w && small_h > big_h){
				big -> rank = (small -> rank) + 1;
			}else{
				if(big -> rank == small -> rank){
					continue;
				}else if(big -> rank > small -> rank){
					small -> rank = big -> rank;
				}else{
					big -> rank = small -> rank;
				}
				continue;
			}
		}
	}
}
