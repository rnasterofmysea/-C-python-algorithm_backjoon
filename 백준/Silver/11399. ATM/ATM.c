#include <stdio.h>
#include <stdlib.h>

int N = 0;
int people[1000] = {0};
int dp[1001];
// 비교 함수 (오름차순 정렬)
int compare_asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    scanf("%d", &N);

    for(int i = 0 ; i < N; i ++ ){
        scanf("%d", &people[i]);
    }

    qsort(people, N, sizeof(int), compare_asc);

    dp[0] = people[0];
    for(int i = 1; i < N; i++){
        dp[i] = dp[i-1] + people[i];
    }

    int result = 0;
    for(int i = 0; i < N; i ++){
        result += dp[i];
    }

    printf("%d", result);
    return 0;
}
