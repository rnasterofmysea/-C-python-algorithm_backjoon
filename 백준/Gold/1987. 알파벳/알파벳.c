/*
BOJ_1987_알파벳
https://www.acmicpc.net/problem/1987

*/

/*
0,0 시작
요구사항
상하좌우 다 가봐야함
알파벳은 전부 대문자

더 이상 갈 곳이 없을 경우 return count;

배열 범위 안에 있고 && visited == 0 일 경우 -- 재귀조건

*/
#include <stdio.h>

int alphabet_check[26]; // 알파벳 방문 여부 체크
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char board[20][20];
int C, R; // 가로, 세로
int MAX = 0;

void dfs(int x, int y, int count) {
    // 현재 알파벳 방문 체크
    alphabet_check[board[y][x] - 'A'] = 1;

    // 최대값 갱신
    if (MAX < count) {
        MAX = count;
    }

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        // 배열 범위 체크 및 새로운 알파벳인지 확인
        if (0 <= nx && nx < C && 0 <= ny && ny < R && alphabet_check[board[ny][nx] - 'A'] == 0) {
            dfs(nx, ny, count + 1);
        }
    }

    // 탐색 종료 후 현재 알파벳 방문 해제
    alphabet_check[board[y][x] - 'A'] = 0;
}

int main() {
    // 입력
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", board[i]);
    }

    // DFS 시작
    dfs(0, 0, 1);

    // 결과 출력
    printf("%d", MAX);
    return 0;
}
