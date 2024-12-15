#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (qsort용)
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// lower_bound 구현: 특정 값 이상의 첫 위치 반환
int lower_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// upper_bound 구현: 특정 값보다 큰 첫 위치 반환
int upper_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int N, M;

    // 상근이가 가진 숫자 카드 입력
    scanf("%d", &N);
    int* cards = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    // 정렬
    qsort(cards, N, sizeof(int), compare);

    // 쿼리 입력 및 처리
    scanf("%d", &M);
    int query;
    for (int i = 0; i < M; i++) {
        scanf("%d", &query);
        int lower = lower_bound(cards, N, query);
        int upper = upper_bound(cards, N, query);
        printf("%d ", upper - lower); // 등장 횟수 출력
    }

    // 메모리 해제
    free(cards);

    return 0;
}
