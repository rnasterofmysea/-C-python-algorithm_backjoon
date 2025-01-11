#include <stdio.h>

// 주사위 상태 초기화
int top = 0, bottom = 0, front = 0, back = 0, left = 0, right = 0;

// 주사위 굴리기 함수
void roll_dice(int direction) {
    int temp;
    switch (direction) {
        case 1:  // 동쪽
            temp = top;
            top = left;
            left = bottom;
            bottom = right;
            right = temp;
            break;
        case 2:  // 서쪽
            temp = top;
            top = right;
            right = bottom;
            bottom = left;
            left = temp;
            break;
        case 3:  // 북쪽
            temp = top;
            top = front;
            front = bottom;
            bottom = back;
            back = temp;
            break;
        case 4:  // 남쪽
            temp = top;
            top = back;
            back = bottom;
            bottom = front;
            front = temp;
            break;
    }
}

int main() {
    int N, M, x, y, K;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    // 지도 입력
    int board[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // 명령 입력
    int commands[1000];
    for (int i = 0; i < K; i++) {
        scanf("%d", &commands[i]);
    }

    // 이동 방향 (동, 서, 북, 남)
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < K; i++) {
        int cmd = commands[i];
        int nx = x + dx[cmd - 1];
        int ny = y + dy[cmd - 1];

        // 지도 범위를 벗어나면 무시
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        // 주사위 굴리기
        roll_dice(cmd);

        // 지도와 주사위 상호작용
        if (board[nx][ny] == 0) {
            board[nx][ny] = bottom;
        } else {
            bottom = board[nx][ny];
            board[nx][ny] = 0;
        }

        // 주사위 상단 값 출력
        printf("%d\n", top);

        // 주사위 위치 업데이트
        x = nx;
        y = ny;
    }

    return 0;
}