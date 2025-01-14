#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n); // 삼각형의 크기 입력

    // 삼각형 입력
    int **triangle = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    // DP 배열 초기화
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc((i + 1) * sizeof(int));
    }

    dp[0][0] = triangle[0][0]; // 초기값 설정

    // DP 배열 채우기
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }

    // 마지막 행에서 최대값 찾기
    int result = dp[n - 1][0];
    for (int j = 1; j < n; j++) {
        if (dp[n - 1][j] > result) {
            result = dp[n - 1][j];
        }
    }

    printf("%d\n", result);

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
        free(dp[i]);
    }
    free(triangle);
    free(dp);

    return 0;
}