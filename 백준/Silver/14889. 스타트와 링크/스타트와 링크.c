#include <stdio.h>
#include <stdlib.h>
/*
https://www.acmicpc.net/problem/14889
BOJ_15889_스타와 링크

1. 백트래킹1 -> 스타팀 / 링크 경우의 수(N과 M 원리)
    - 기저조건: depth = N이 되었을 경우( 0 - N/2: 스타 팀, N/2 ~ N: 링크 팀)
    - visited을 통해 백트래킹 구현
2. 능력치 비교
3. 결과: 능력차이의 최소값
*/
int N = 0;
int total_arry[20][20];
int visited[20];
int team_arry[20];
int MIN = 100;
int statDiff(){
    int star_stats = 0;
    int link_stats = 0;
    
    for(int i = 0 ; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(visited[i] && visited[j]){
                star_stats += total_arry[i][j];    
            }

            if(!visited[i] && !visited[j]){
                link_stats += total_arry[i][j];    
            }
        }
    }
    return abs(star_stats - link_stats);
}

void dfs(int depth, int idx) {
    if (depth == N/2) { // N개의 숫자를 모두 선택한 경우
        int result = statDiff();
        if(MIN > result){
            MIN = result;
        }
        return;
    }

    for(int i =  idx; i < N ; i ++){
        if(!visited[i]){
            visited[i] = 1;
            team_arry[depth] = i;
            dfs(depth+1, i+1);
            visited[i] = 0;
        }
    }
};
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            scanf("%d", &total_arry[i][j]);
        }
    }

    dfs(0,0);
    printf("%d", MIN);
    return 0;
}