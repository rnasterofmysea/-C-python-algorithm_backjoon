#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000000  // 메모리 제한을 고려한 배열 크기 조정

long long hash[HASH_SIZE];

long long A(long long n, int P, int Q) {
    if (n == 0) {
        return 1;  // 기본값 설정 (예시로 1 사용)
    }
    if (n < HASH_SIZE && hash[n] != 0) {
        return hash[n];
    }

    long long result = A(n / P, P, Q) + A(n / Q, P, Q);
    
    if (n < HASH_SIZE) {
        hash[n] = result;
    }

    return result;
}

int main() {
    long long N;
    int P, Q;

    scanf("%lld %d %d", &N, &P, &Q);

    printf("%lld\n", A(N, P, Q));
    return 0;
}
