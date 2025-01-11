#include <stdio.h>
#include <stdlib.h>

// 비교 함수
int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int)); // 동적 배열 할당
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 정렬
    qsort(arr, N, sizeof(int), compare);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr); // 동적 메모리 해제
    return 0;
}
