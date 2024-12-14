#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (qsort를 위해 사용)
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) {
        return -1;  // x가 y보다 작을 때
    } else if (x > y) {
        return 1;   // x가 y보다 클 때
    } else {
        return 0;   // x와 y가 같을 때
    }
}

int binary_search(int *arr, int value, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value) {
            return 1;
        } else if (arr[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return 0;
}

int main() {
    int N, M;

    // 첫 번째 배열 입력
    scanf("%d", &N);
    int *N_arry = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &N_arry[i]);
    }

    // 두 번째 배열 입력
    scanf("%d", &M);
    int *M_arry = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &M_arry[i]);
    }

    // 첫 번째 배열 정렬
    qsort(N_arry, N, sizeof(int), compare);

    // 두 번째 배열의 각 값에 대해 이진 탐색 실행
    for (int i = 0; i < M; i++) {
        printf("%d\n", binary_search(N_arry, M_arry[i], 0, N - 1));
    }

    // 메모리 해제
    free(N_arry);
    free(M_arry);

    return 0;
}
