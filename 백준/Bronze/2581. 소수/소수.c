#include <stdio.h>

int main() {
    int M, N = 0;
    scanf("%d", &M);
    scanf("%d", &N);

    int sum = 0;
    int min = 1000000;
    for(int i = M; i <= N; i++){
        int flag = 0;
        if(i == 1){
            continue;
        }
        for(int j = 2; j < i; j++){
            int temp = i % j;
            if(temp == 0){
                flag = -1;
                break;
            }
        }
        if(flag == 0){
            sum += i;
            if(min > i){
                min = i;
            }
        }
    }

    if(sum == 0){
        printf("-1");
    } else{
        printf("%d\n", sum);
        printf("%d", min);
    }
    return 0;
}