#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // n이 1 또는 2일 때는 미리 출력
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n == 2) {
        printf("2\n");
        return 0;
    }
    
    // 동적 프로그래밍 배열 초기화
    int dp[1001] = {0}; // n 최대값이 1000이므로 크기 설정
    dp[1] = 1;
    dp[2] = 2;

    // 점화식으로 dp 배열 계산
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    
    // 결과 출력
    printf("%d\n", dp[n]);
    return 0;
}
