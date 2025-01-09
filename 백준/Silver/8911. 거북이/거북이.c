#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

// 방향: 북(0), 동(1), 남(2), 서(3)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n;
    char commands[MAX_LEN + 1];
    scanf("%d", &n);

    while (n--) {
        scanf("%s", commands);
        
        int x = 0, y = 0; // 현재 좌표
        int dir = 0;      // 현재 방향 (북쪽)

        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;

        int len = strlen(commands);
        for (int i = 0; i < len; i++) {
            char cmd = commands[i];
            if (cmd == 'F') { // 앞으로 이동
                x += dx[dir];
                y += dy[dir];
            } else if (cmd == 'B') { // 뒤로 이동
                x -= dx[dir];
                y -= dy[dir];
            } else if (cmd == 'L') { // 왼쪽 회전
                dir = (dir + 3) % 4;
            } else if (cmd == 'R') { // 오른쪽 회전
                dir = (dir + 1) % 4;
            }

            // 방문 좌표의 최소/최대 갱신
            if (x < min_x) min_x = x;
            if (x > max_x) max_x = x;
            if (y < min_y) min_y = y;
            if (y > max_y) max_y = y;
        }

        // 직사각형 넓이 계산
        int area = (max_x - min_x) * (max_y - min_y);
        printf("%d\n", area);
    }
}

int main() {
    solve();
    return 0;
}
