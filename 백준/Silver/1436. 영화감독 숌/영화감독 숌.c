#include <stdio.h>
#include <string.h>

int main() {
    // 제일 작은 종말의 수 666
    int N;
    scanf("%d", &N);

    int start = 666; // 시작 숫자
    int count = 1;   // 현재 종말의 수 개수

    while (count < N) {
        start++; // 다음 숫자 확인

        // 숫자를 문자열로 변환
        char str[12]; // 12는 int 최대 자릿수를 커버
        sprintf(str, "%d", start);

        // "666"이 포함되어 있는지 확인
        if (strstr(str, "666")) {
            count++;
        }
    }

    printf("%d\n", start); // N번째 종말의 수 출력
    return 0;
}
