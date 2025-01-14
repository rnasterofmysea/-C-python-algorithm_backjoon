/*
https://www.acmicpc.net/problem/1463
C_BOJ_1463_1로 만들기
*/

#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int N;
    scanf("%d", &N);

    int dp[N + 1];

    dp[1] = 0; // 초기값

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1; // 1을 뺀 경우

        if (i % 2 == 0) {
            dp[i] = MIN(dp[i], dp[i / 2] + 1); // 2로 나누어떨어지는 경우
        }
        if (i % 3 == 0) {
            dp[i] = MIN(dp[i], dp[i / 3] + 1); // 3으로 나누어떨어지는 경우
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}
