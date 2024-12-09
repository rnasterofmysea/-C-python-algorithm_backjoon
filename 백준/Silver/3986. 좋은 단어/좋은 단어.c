#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    getchar(); // 버퍼에 남아 있는 줄바꿈 제거

    int result = 0; // 좋은 단어 개수
    char *input = NULL;
    size_t buffer_size = 0;

    for (int i = 0; i < N; i++) {
        getline(&input, &buffer_size, stdin);
        int len = strlen(input);

        // 줄 바꿈 문자 제거
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        // 홀수 길이 단어는 스킵
        if (len % 2 != 0) {
            continue;
        }

        // 스택 초기화
        int *stack = (int *)malloc(len * sizeof(int));
        int top = -1;

        for (int j = 0; j < len; j++) {
            if (top >= 0 && stack[top] == input[j]) {
                top--; // 짝지어진 문자 제거
            } else {
                stack[++top] = input[j]; // 문자 추가
            }
        }

        // 스택이 비어 있으면 좋은 단어
        if (top == -1) {
            result++;
        }

        free(stack);
    }

    printf("%d", result);
    free(input);
    return 0;
}
