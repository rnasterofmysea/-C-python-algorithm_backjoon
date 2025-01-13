#include <stdio.h>

#define OFFSET 1000000 // 음수 처리용 오프셋
#define SIZE 2000001   // -1,000,000 ~ 1,000,000 범위를 커버하기 위한 크기

int main() {
    int N;
    scanf("%d", &N);

    int count[SIZE] = {0}; // 카운팅 배열 초기화

    // 입력된 숫자의 빈도 계산
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        count[num + OFFSET]++; // 음수를 양수 인덱스로 변환
    }

    // 카운팅 배열을 기반으로 내림차순 정렬된 결과 출력
    for (int i = SIZE - 1; i >= 0; i--) {
        while (count[i] > 0) {
            printf("%d\n", i - OFFSET); // 원래 숫자로 변환
            count[i]--;
        }
    }

    return 0;
}