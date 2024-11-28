#include <stdio.h>
#include <string.h>

int main(void) {
    int n, sum = 0;
    char numbers[101];  // 최대 100자리 숫자 + '\0'

    // 입력받기
    scanf("%d", &n);      // 숫자의 개수
    scanf("%s", numbers); // 숫자 문자열

    // 숫자 합 계산
    for (int i = 0; i < n; i++) {
        sum += numbers[i] - '0';  // 문자 -> 숫자 변환 후 합산
    }

    // 결과 출력
    printf("%d\n", sum);

    return 0;
}
