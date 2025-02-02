/*
C_BOJ_16401_과자 나눠주기
https://www.acmicpc.net/problem/16401
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000  // 문제 조건에 따른 최대 크기

// 비교 함수 (오버플로우 방지)
int compare(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// 이진 탐색 함수 (while 사용)
int binary_search(int arr[], int size, int target) {
    int start = 1;
    int end = arr[size - 1];
    int mid = 0;
    int result = 0;
    while (start <= end) {
        mid = start + (end - start) / 2;
        int count = 0;
        for(int i = 0 ; i < size ; i++){
            count += arr[i] / mid;
        }
        
        if(count < target){
            end = mid -1;
        } else {
            result = mid;
            start = mid + 1;
        }
    }

    return result;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[MAX_SIZE] = {0};
    for(int i = 0; i < N; i ++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
   
    int result = binary_search(arr, N, M);
    printf("%d", result);
    return 0;
}
