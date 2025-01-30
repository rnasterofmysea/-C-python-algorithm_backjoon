/*
C_BOJ_2217_로프
https://www.acmicpc.net/problem/2217
*/

#include <stdio.h>
#include <stdlib.h>
int N = 0;
int arry[100000];

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
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
       scanf("%d", &arry[i]);     
    }
    // 정렬
    qsort(arry, N, sizeof(int), compare);
    int max = 0;
    for(int i = 0; i < N; i ++){
        int current = arry[i];
        int temp = current * (N - i);
        if(temp > max){
            max = temp;
        }
    }

    printf("%d", max);
    
    return 0;
}