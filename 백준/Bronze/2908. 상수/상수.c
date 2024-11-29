#include <stdio.h>
#include <stdlib.h> // atoi 함수 사용을 위해 필요

int main(void) {
    char input[2][4]; // 각 숫자는 최대 3자리 + 널 문자 포함

    // 두 개의 숫자 입력
    scanf("%3s", input[0]); // 첫 번째 숫자
    scanf("%3s", input[1]); // 두 번째 숫자

    // 숫자 뒤집기
    for (int i = 0; i < 2; i++) {
        char temp = input[i][2];
        input[i][2] = input[i][0];
        input[i][0] = temp;
    }

    // 뒤집힌 숫자를 정수로 변환
    int front = atoi(input[0]);
    int back = atoi(input[1]);

    // 더 큰 숫자 출력
    if (front <= back) {
        printf("%d\n", back);
    } else {
        printf("%d\n", front);
    }

    return 0;
}
