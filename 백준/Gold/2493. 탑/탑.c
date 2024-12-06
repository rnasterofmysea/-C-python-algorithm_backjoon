#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d", &N);

    int tower_arry[N];
    int result[N];
    int stack[N]; // 인덱스를 저장하는 스택
    int top = -1; // 스택 최상단

    // 탑 높이 입력받기
    for (int i = 0; i < N; i++) {
        scanf("%d", &tower_arry[i]);
    }

    // 스택을 이용하여 결과 계산
    for (int i = 0; i < N; i++) {
        // 스택에서 현재 탑보다 작거나 같은 높이의 탑 제거
        while (top >= 0 && tower_arry[stack[top]] <= tower_arry[i]) {
            top--;
        }

        // 스택이 비어 있으면 왼쪽에 더 높은 탑이 없음
        if (top < 0) {
            result[i] = 0;
        } else {
            // 스택의 최상단 값이 더 높은 탑
            result[i] = stack[top] + 1; // 1-based index
        }

        // 현재 탑의 인덱스를 스택에 추가
        stack[++top] = i;
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
