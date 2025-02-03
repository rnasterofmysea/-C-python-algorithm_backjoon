/*
C_BOJ_2295_세 수의 합
https://www.acmicpc.net/problem/2295

*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int U[n];
    int S[n * n];
    int s_index = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &U[i]);
    }

    qsort(U, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            S[s_index++] = U[i] + U[j];
        }
    }

    qsort(S, s_index, sizeof(int), compare);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int target = U[i] - U[j];
            if (binary_search(S, s_index, target)) {
                printf("%d\n", U[i]);
                return 0;
            }
        }
    }

    return 0;
}
