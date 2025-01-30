/*
https://www.acmicpc.net/problem/1931
C_BOJ_1931_회의실 배정
*/

#include <stdio.h>
#include <stdlib.h>


int conferences[100001][2] = {0};
int N = 0;
int result = 0;

// 비교 함수
int compare(const void *a, const void *b) {
    const int *rowA = (const int *)a;
    const int *rowB = (const int *)b;

    // 첫 번째 열(arry[][0])을 기준으로 정렬
    if (rowA[1] != rowB[1]) {
        return rowA[1] - rowB[1]; // 오름차순
    }

    // 첫 번째 값이 같으면 첫 번째 열(arry[][0])을 기준으로 정렬
    return rowA[0] - rowB[0]; // 오름차순
}

int main() {
    
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d %d", &conferences[i][0], &conferences[i][1]);    
    }
    
    qsort(conferences, N, sizeof(conferences[0]), compare);

    // //TESTING SORT
    // printf("Sorted array: \n");
    // for (int i = 0; i < N; i++) {
    //     printf("%d %d \n", conferences[i][0], conferences[i][1]);
    // }

    int current_time = conferences[0][1];
    result ++;

    for(int i = 1; i < N; i ++){
        if(current_time <= conferences[i][0]){
            current_time = conferences[i][1];
            result ++;
        }
    }

    printf("%d",result);
    return 0;
}