/*
C_BOJ_16401_과자 나눠주기
https://www.acmicpc.net/problem/16401
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000  // 문제 조건에 따른 최대 크기


// 이진 탐색 함수 (while 사용)
int binary_search(int arr[], int size, int target, int max) {
    int start = 1;
    int end = max;
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
    int max = -1;
    for(int i = 0; i < N; i ++){
        scanf("%d", &arr[i]);
        if(max < arr[i]){
            max = arr[i];
        }
    }
   
    int result = binary_search(arr, N, M, max);
    printf("%d", result);
    return 0;
}
