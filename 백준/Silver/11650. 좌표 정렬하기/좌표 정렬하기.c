#include <stdio.h>
#include <stdlib.h>

int N = 0;
int arry[100000][2];

// 비교 함수
int compare(const void *a, const void *b) {
    const int *rowA = (const int *)a;
    const int *rowB = (const int *)b;

    // 첫 번째 열(arry[][0])을 기준으로 정렬
    if (rowA[0] != rowB[0]) {
        return rowA[0] - rowB[0]; // 오름차순
    }

    // 첫 번째 값이 같으면 두 번째 열(arry[][1])을 기준으로 정렬
    return rowA[1] - rowB[1]; // 오름차순
}

int main() {
    // 입력 받기
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arry[i][0], &arry[i][1]);
    }

    // 정렬
    qsort(arry, N, sizeof(arry[0]), compare);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arry[i][0], arry[i][1]);
    }

    return 0;
}
