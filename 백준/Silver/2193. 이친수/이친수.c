#include <stdio.h>

/*
F(1) 1
F(2) 10 
F(3) 100 101
F(4) 1000 1010 1001
F(5) 100000 10100 10010 10001 10101
*/

long long dp[91] = {0};
int main() {
    int N = 0;
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i<= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    printf("%lld", dp[N]);
    return 0;
}