#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}
// lower_bound: target 이상의 첫 위치 반환
int lower_bound(int *arr, int size, int target) {
    int start = 0, end = size;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

// upper_bound: target보다 큰 첫 위치 반환
int upper_bound(int *arr, int size, int target) {
    int start = 0, end = size;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main() {
    // N 및 N 배열 입력
    int N = 0;
    scanf("%d", &N);
    int *N_arry = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &N_arry[i]);
    }

    // M 및 M 배열 입력
    int M = 0;
    scanf("%d", &M);
    int *M_arry = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &M_arry[i]);
    }

    // N 배열 정렬
    qsort(N_arry, N, sizeof(int), compare);

    // M 배열의 각 값에 대해 N 배열에서 등장 횟수 계산
    for (int i = 0; i < M; i++) {
        int lower = lower_bound(N_arry, N, M_arry[i]);
        int upper = upper_bound(N_arry, N, M_arry[i]);
        printf("%d ", upper - lower); // 등장 횟수 출력
    }

    // 메모리 해제
    free(N_arry);
    free(M_arry);

    return 0;
}
