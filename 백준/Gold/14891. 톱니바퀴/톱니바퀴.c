#include <stdio.h>

int cogwheels[4][8];
int currents[4] = {0};
int K;

void rotation(int num1, int num2, int flag) {
    int left = cogwheels[num1][(currents[num1] + 6) % 8];  // 현재 톱니바퀴의 왼쪽 톱니
    int right = cogwheels[num1][(currents[num1] + 2) % 8]; // 현재 톱니바퀴의 오른쪽 톱니

    // 회전 전파
    if (flag == 0) {
        // 왼쪽 비교
        if (0 <= num1 - 1 && left != cogwheels[num1 - 1][(currents[num1 - 1] + 2) % 8]) {
            rotation(num1 - 1, -num2, flag - 1);
        }
        // 오른쪽 비교
        if (num1 + 1 < 4 && right != cogwheels[num1 + 1][(currents[num1 + 1] + 6) % 8]) {
            rotation(num1 + 1, -num2, flag + 1);
        }
    } else if (flag < 0) {
        // 왼쪽 비교
        if (0 <= num1 - 1 && left != cogwheels[num1 - 1][(currents[num1 - 1] + 2) % 8]) {
            rotation(num1 - 1, -num2, flag - 1);
        }
    } else if (flag > 0) {
        // 오른쪽 비교
        if (num1 + 1 < 4 && right != cogwheels[num1 + 1][(currents[num1 + 1] + 6) % 8]) {
            rotation(num1 + 1, -num2, flag + 1);
        }
    }

    // 회전 전파가 완료된 후에 currents 업데이트
    if (num2 == 1) { // 시계 방향
        currents[num1] = (currents[num1] + 7) % 8;
    } else if (num2 == -1) { // 반시계 방향
        currents[num1] = (currents[num1] + 1) % 8;
    }
}

int main() {
    // 톱니바퀴 상태 입력
    for (int i = 0; i < 4; i++) {
        char temp[9];
        scanf("%s", temp);
        for (int j = 0; j < 8; j++) {
            cogwheels[i][j] = temp[j] - '0';
        }
    }

    // 회전 명령 입력
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        rotation(num1 - 1, num2, 0); // 톱니바퀴 번호는 0부터 시작
    }

    // 점수 계산
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (cogwheels[i][currents[i]] == 1) {
            score += (1 << i);
        }
    }
    printf("%d\n", score);

    return 0;
}