#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arry[1000000];
    int result[1000000];
    int stack[1000000];
    int top = -1;

    // 배열 입력
    for (int i = 0; i < N; i++) {
        scanf("%d", &arry[i]);
    }

    // 배열을 뒤에서부터 탐색
    for (int i = N - 1; i >= 0; i--) {
        // 스택에서 현재 값보다 작은 값 제거
        while (top >= 0 && stack[top] <= arry[i]) {
            top--;
        }

        // 스택이 비어있지 않다면 오큰수 설정
        if (top >= 0) {
            result[i] = stack[top];
        } else {
            result[i] = -1;
        }

        // 현재 값을 스택에 push
        stack[++top] = arry[i];
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
