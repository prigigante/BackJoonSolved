#include <stdio.h>

int main(void){
    int visitor = 0, t_shirt_bundle_size =0, pancile_bundle_size =0, pancile_bundle =0, t_shirt_bundle =0, pancile_left =0;
    int array[6] = {0,};
    scanf("%d", &visitor);
    for(int i=0; i<6; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d %d", &t_shirt_bundle_size, &pancile_bundle_size);
    pancile_bundle = visitor / pancile_bundle_size;
    pancile_left = visitor % pancile_bundle_size;

    for(int i=0; i < 6; i++){
        t_shirt_bundle = t_shirt_bundle + array[i] / t_shirt_bundle_size;
        if(array[i] % t_shirt_bundle_size > 0){
            t_shirt_bundle++;
        }
    }
    printf("%d\n%d %d", t_shirt_bundle, pancile_bundle, pancile_left);
    return 0;
}