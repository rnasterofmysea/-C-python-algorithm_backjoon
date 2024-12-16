#include <stdio.h>
#include <stdlib.h>

// 오름차순 비교 함수
int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1 > num2) - (num1 < num2);
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    // A 배열 입력
    int *A_arry = (int *)malloc(A * sizeof(int));
    for (int i = 0; i < A; i++) {
        scanf("%d", &A_arry[i]);
    }

    // B 배열 입력
    int *B_arry = (int *)malloc(B * sizeof(int));
    for (int i = 0; i < B; i++) {
        scanf("%d", &B_arry[i]);
    }

    // B 배열 정렬
    qsort(B_arry, B, sizeof(int), compare);

    // 결과 저장용 배열
    int *result_arry = (int *)malloc(A * sizeof(int));
    int index = 0;

    // A 배열의 각 값에 대해 B 배열에서 이분 탐색
    for (int i = 0; i < A; i++) {
        int start = 0;
        int end = B - 1;
        int found = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (B_arry[mid] == A_arry[i]) {
                found = 1; // 값이 존재함
                break;
            } else if (B_arry[mid] > A_arry[i]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // B 배열에 A[i]가 존재하지 않으면 결과 배열에 추가
        if (!found) {
            result_arry[index++] = A_arry[i];
        }
    }

    // 결과 배열 정렬
    if (index > 0) {
        qsort(result_arry, index, sizeof(int), compare);
        // 결과 출력
        printf("%d\n", index); // 결과 배열 크기
        for (int i = 0; i < index; i++) {
        printf("%d ", result_arry[i]); 
        }
    }
    else{
        printf("0");
    }

    // 메모리 해제
    free(A_arry);
    free(B_arry);
    free(result_arry);

    return 0;
}
