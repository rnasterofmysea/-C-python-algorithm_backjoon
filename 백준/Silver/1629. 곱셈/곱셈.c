#include <stdio.h>

// 분할정복을 이용한 거듭제곱 계산 함수
long long modular_exponentiation(long long base, long long exp, long long mod) {
    if (exp == 0) return 1; // 지수가 0이면 결과는 1
    long long half = modular_exponentiation(base, exp / 2, mod);
    half = (half * half) % mod; // 중간 계산 결과에 모듈러 연산 적용
    if (exp % 2 == 1) { // 지수가 홀수인 경우
        half = (half * base) % mod;
    }
    return half;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C); // 입력 받기
    printf("%lld\n", modular_exponentiation(A, B, C)); // 결과 출력
    return 0;
}
