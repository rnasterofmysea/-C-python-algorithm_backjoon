#include <stdio.h>

void soinsu(int N) {
    for (int i = 2; i <= N; i++) { // 2부터 시작하여 N까지 반복
        while (N % i == 0) {      // i가 소인수인지 확인
            printf("%d\n", i);    // 소인수 출력
            N /= i;               // N을 i로 나누기
        }
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    soinsu(N); // 소인수 분해 함수 호출

    return 0;
}
