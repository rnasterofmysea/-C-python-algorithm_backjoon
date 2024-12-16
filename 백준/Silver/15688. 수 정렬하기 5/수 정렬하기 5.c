#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2){
        return -1;
    }else if(num1 > num2){
        return 1;
    }else{
        return 0;
    }
}
int main() {
    
    int N = 0;
    scanf("%d", &N);

    int *N_arry = (int *)malloc(N * sizeof(int));
    
    for(int i = 0; i < N; i ++){
        scanf("%d", &N_arry[i]);
    }

    qsort(N_arry, N, sizeof(int), compare);
    for(int i = 0; i < N ; i++){
        printf("%d\n",N_arry[i]);
    }

    free(N_arry);
    return 0;
}