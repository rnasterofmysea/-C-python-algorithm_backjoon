#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 숫자 합 계산 함수
int sum_of_digits(const char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ('0'<=str[i] && str[i] <= '9' ) {
            sum += str[i] - '0';
        }
    }
    return sum;
}

// 비교 함수: 길이 -> 숫자 합 -> 사전순
int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // 1. 길이 비교
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return len1 - len2; // 길이가 짧은 순으로 정렬
    }

    // 2. 숫자 합 비교
    int sum1 = sum_of_digits(str1);
    int sum2 = sum_of_digits(str2);
    if (sum1 != sum2) {
        return sum1 - sum2; // 숫자 합이 작은 순으로 정렬
    }

    // 3. 사전순 비교
    return strcmp(str1, str2);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // 개행 문자 제거

    // 동적 메모리를 사용하여 문자열 배열 생성
    char **serials = malloc(N * sizeof(char *));

    for (int i = 0; i < N; i++) {
        size_t buffer = 0;
        char *input = NULL;

        // 한 줄 입력
        getline(&input, &buffer, stdin);
        size_t len = strlen(input);

        // 개행 문자 제거
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }
        serials[i] = strdup(input); // 문자열 복사
    }

    // 정렬 수행
    qsort(serials, N, sizeof(char *), compare);

    // 정렬된 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%s\n", serials[i]);
        free(serials[i]); // 동적 메모리 해제
    }
    free(serials); // 배열 메모리 해제

    return 0;
}
