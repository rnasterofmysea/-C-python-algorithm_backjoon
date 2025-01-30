/*
C_BOJ_1788_피보나치의 확장
https://www.acmicpc.net/problem/1788
F(n) = F(n-1) + F(n-2)

F(n) 양음수 처리 / 값 반환 이슈
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DIV 1000000000
int main() {
    int n = 0;
    scanf("%d", &n);
    if(n == 0){
        printf("0\n0");   
    }else if(n > 0){
        long long int dp[1000001] = {0};
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n;i++){
            dp[i] = (dp[i-1] + dp[i-2])% DIV;
        }
        printf("1\n%lld", dp[n]);
    } else{
        n = -n;
        long long int dp[1000001] = {0};
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n ; i ++){
            dp[i] = -(dp[i-1] - dp[i-2])%DIV;
        }
        if(dp[n] > 0){
            printf("1\n%lld", dp[n]);
        } else {
            printf("-1\n%lld", llabs(dp[n]));
        }
    }
    return 0;
}