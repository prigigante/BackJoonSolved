#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int high, int low, int* main_array, int* sub_array);


int main(void){
	int input_size = 0, cut_size = 0;
	double temp_double = 0;
	
	int* array = NULL, *temp_array = NULL;
	double rv = 0;
	scanf("%d", &input_size);
	if(input_size == 0){
		printf("0");
		return 0;
	}
	temp_double = input_size;
	temp_double = temp_double * 0.15;
	
//	cut_size =(int) temp_double;
//	if(temp_double - cut_size >0){
//		cut_size = cut_size + 1;
	//} // I think this code need to modified
	
	cut_size = (int) (round(temp_double));
//	printf("%lf %d<< is the cut_size\n", temp_double, cut_size);
	array = (int*) malloc(sizeof(int) * (input_size));
	temp_array = (int*) malloc(sizeof(int) *(input_size));
	for(int i =0; i < input_size; i++){
		scanf("%d", (array+i));

	}
	mergeSort(0, input_size-1, array,temp_array);
	
	for(int i = cut_size; i<input_size - cut_size; i++){
		rv = rv + *(array + i);
	}
	rv = rv / (input_size -(2*cut_size));
	rv = round(rv);
	
//	for(int i=0; i<input_size; i++){
//		printf("%d <<\n", *(array + i));
//	}

//	printf("%d <<< rv\n", (int) rv);

	printf("%d", (int) rv);
	return 0;
}

void mergeSort(int low, int high, int* main_array, int* sub_array){
	if(high - low <= 0){
		return;
	}
	int mid = 0;
	mid = (high + low) / 2;

	mergeSort(low, mid, main_array, sub_array);
	mergeSort(mid+1, high, main_array, sub_array);

	int left_condition = 0, right_condition = 0, counter =0;
	left_condition = low, right_condition = mid+1, counter = low;

	for( ; counter<= high; counter++){
		if(right_condition > high){
			*(sub_array + counter) = *(main_array + left_condition);
			left_condition++;
		}else if(left_condition > mid){
			*(sub_array + counter) = *(main_array + right_condition);
			right_condition++;
		}else if(*(main_array + left_condition) <= *(main_array + right_condition)){
			*(sub_array + counter) = *(main_array + left_condition);
			left_condition++;
		}else{
			*(sub_array + counter) = *(main_array + right_condition);
			right_condition++;
		}
	}

	for(counter = low; counter <= high; counter++){
		*(main_array + counter) = *(sub_array + counter);
	}
}
