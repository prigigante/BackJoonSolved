#include <stdio.h>

void MergeSort(int array1[], int low, int high, int array2[]);
// https://ko.wikipedia.org/wiki/%ED%95%A9%EB%B3%91_%EC%A0%95%EB%A0%AC
//위의 함수는 위의 링크에서 가져옴

void printArray(int array[], int array_size);

int main(void){
    int test_array[10] = {4,8,6,5,7,9,3,2,0,1};
    int temp_array[10] = {0,};

    printArray(test_array, 10);

    MergeSort(test_array, 0 , 9, temp_array);

    printArray(test_array, 10);


    return 0;

}

void MergeSort(int array1[], int low, int high, int array2[]){
    if(low >= high) return;

    int mid = (low + high) / 2;
    
    MergeSort(array1, low, mid, array2);
    MergeSort(array1, mid+1, high, array2);

    int i=low, j = mid +1, k = low;
    for( ; k<=high; ++k){
        if(j > high) {
            array2[k] = array1[i++]; // 오른쪽 분할이 다 끝나는 경우
        }else if (i > mid){
            array2[k] = array1[j++];  // 왼쪽 분할이 전부 끝난 경우우
        }else if(array1[i] <= array1[j]){
            array2[k] = array1[i++]; // 요놈과
        }else{
            array2[k] = array1[j++]; //요놈 이 둘이 각각의 분산된 배열의 맨 앞을 가리킴
        }
        
    }

    for(i = low; i <= high; ++i){
        array1[i] = array2[i];
    }
    //I think in this case, the array2 is temp array
}
void printArray(int array[], int array_size){
    printf("\nprint start\n");
    for(int i =0; i < array_size; i++){
        printf("%d ", array[i]);
    }
    printf("\nprint end\n");
}