#include <stdio.h>

int direction_x[4] = {0, 1, 0, -1}; // 북, 동, 남, 서
int direction_y[4] = {-1, 0, 1, 0};
int room[50][50];
int N, M;
int count = 0;

void backtracking_cleaning(int x, int y, int d) {
    // 1. 현재 칸이 청소되지 않은 경우 청소한다.
    if (room[y][x] == 0) {
        room[y][x] = -1; // 청소한 곳은 -1로 표시
        count++;
    }

    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
    for (int i = 0; i < 4; i++) {
        int nd = (d + 3 - i) % 4; // 반시계 방향으로 90도 회전
        int nx = x + direction_x[nd];
        int ny = y + direction_y[nd];

        // 청소되지 않은 빈 칸이 있다면 이동
        if (0 <= nx && nx < M && 0 <= ny && ny < N && room[ny][nx] == 0) {
            backtracking_cleaning(nx, ny, nd);
            return;
        }
    }

    // 2. 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    int nd = (d + 2) % 4; // 뒤쪽 방향
    int nx = x + direction_x[nd];
    int ny = y + direction_y[nd];

    // 후진 가능한 경우 후진
    if (0 <= nx && nx < M && 0 <= ny && ny < N && room[ny][nx] != 1) {
        backtracking_cleaning(nx, ny, d); // 방향은 유지한 채로 후진
    } else {
        return; // 후진할 수 없으면 종료
    }
}

int main() {
    int r, c, d;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &room[i][j]);
        }
    }
    backtracking_cleaning(c, r, d);
    printf("%d", count);
    return 0;
}