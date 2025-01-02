/*
BOj_15654_N과M(5)
https://www.acmicpc.net/problem/15654
*/
#include <stdio.h>

int M, N;
int visited[8];
int arry[8];
int input_arry[8];
void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arry[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            // // 현재 숫자가 이전에 선택된 숫자보다 작으면 제외
            // if (depth > 0 && arry[depth - 1] > i + 1) {
            //     continue;
            // }

            arry[depth] = input_arry[i];
            visited[i] = 1;
            dfs(depth + 1);
            visited[i] = 0; // 백트래킹
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i ++){
        scanf("%d", &input_arry[i]);
    }

    int min = 0;
    for(int i = 0; i < N -1; i ++){
        min = i;
        for(int j = i+1; j < N ; j++){
            if(input_arry[min] > input_arry[j]){
                min = j;
            }
        }
        if(i != min){
            int temp = input_arry[i];
            input_arry[i] = input_arry[min];
            input_arry[min] = temp;
        }
    }

    // for(int i = 0; i < N; i ++){
    //     printf("%d \n", input_arry[i]);
    // }
    dfs(0);
    return 0;
}
