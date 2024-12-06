#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // 숫자 개수 입력

    int *sequence = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]); // 목표 수열 입력
    }

    int *stack = (int *)malloc(n * sizeof(int)); // 스택 구현
    int top = -1; // 스택의 최상단 인덱스
    int current = 1; // 스택에 넣을 현재 숫자
    char *result = (char *)malloc(2 * n * sizeof(char)); // 연산 저장
    int result_index = 0;

    for (int i = 0; i < n; i++) {
        int target = sequence[i];

        // 스택에 target까지 숫자 푸시
        while (current <= target) {
            stack[++top] = current++; // push
            result[result_index++] = '+'; // '+' 저장
        }

        // 스택 최상단이 target인 경우 팝
        if (stack[top] == target) {
            top--; // pop
            result[result_index++] = '-'; // '-' 저장
        } else {
            // 불가능한 경우
            printf("NO\n");
            free(sequence);
            free(stack);
            free(result);
            return 0;
        }
    }

    // 결과 출력
    for (int i = 0; i < result_index; i++) {
        printf("%c\n", result[i]);
    }

    free(sequence);
    free(stack);
    free(result);
    return 0;
}
