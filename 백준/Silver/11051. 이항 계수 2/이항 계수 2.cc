#include <stdio.h>

#define MAX 1001
#define MOD 10007

int dp[MAX][MAX];

int main() {
    int N, K;

    // 입력 받기
    scanf("%d %d", &N, &K);

    // 동적 프로그래밍을 통해 이항계수 계산
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;  // C(n, 0) = C(n, n) = 1
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }

    // 결과 출력
    printf("%d\n", dp[N][K]);

    return 0;
}
