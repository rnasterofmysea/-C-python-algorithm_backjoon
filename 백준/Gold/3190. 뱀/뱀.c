/*
C_BOJ_3190 뱀
https://www.acmicpc.net/problem/3190

Keypoint

만약 이동한 칸에 사과가 있다면, 
그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.

만약 이동한 칸에 사과가 없다면, 
몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.

1. 맵 크기 입력받기 > 사과 배치하기

2. 뱀이동 시키기

*/
#include <stdio.h>

// 입력값
int N = 0; // 맵 크기
int K = 0; // 사과 개수
int L = 0; // 방향 전환 횟수

// 게임 세팅
int map[100][100] = {0};
int action_time[100] = {0};
char action_cmd[100] = {0};
int dir_x[4] = {0, 1, 0, -1}; // 오른쪽, 아래, 왼쪽, 위
int dir_y[4] = {1, 0, -1, 0};

// 초기값
int snake[10000][2];
int front = 0, rear = 0; // 큐의 앞과 뒤
int snake_dir = 0;       // 초기 방향: 오른쪽
int phase = 0;           // 방향 전환 단계
int time = 0;            // 게임 시간

// 큐 삽입 (뱀 길이 증가)
void enqueue(int x, int y) {
    snake[rear][0] = x;
    snake[rear][1] = y;
    rear++;
}

// 큐 삭제 (뱀 길이 감소)
void dequeue() {
    front++;
}

// 게임 진행 함수
void game() {
    int x = 0, y = 0; // 뱀의 초기 위치
    enqueue(x, y);    // 초기 뱀 위치 저장

    while (1) {
        // 방향 전환 처리
        if (phase < L && time == action_time[phase]) {
            if (action_cmd[phase] == 'L') {
                snake_dir = (snake_dir + 3) % 4; // 왼쪽 회전
            } else {
                snake_dir = (snake_dir + 1) % 4; // 오른쪽 회전
            }
            phase++;
        }

        time++; // 시간 증가

        // 다음 이동 좌표 계산
        int nx = snake[rear - 1][0] + dir_x[snake_dir];
        int ny = snake[rear - 1][1] + dir_y[snake_dir];

        // 맵 경계 체크
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
            break; // 게임 종료
        }

        // 몸체 충돌 체크
        for (int i = front; i < rear; i++) {
            if (snake[i][0] == nx && snake[i][1] == ny) {
                return; // 게임 종료
            }
        }

        // 사과 여부 확인 및 이동 처리
        if (map[nx][ny] == 1) {
            map[nx][ny] = 0; // 사과 제거
            enqueue(nx, ny); // 뱀 길이 증가
        } else {
            enqueue(nx, ny); // 뱀 머리 이동
            dequeue();       // 뱀 꼬리 제거
        }

        // 디버깅용 출력
    }
}

int main() {
    // 입력 받기
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = 1; // 사과 위치 저장 (1-based -> 0-based)
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &action_time[i], &action_cmd[i]);
    }

    // 게임 실행
    game();

    // 결과 출력
    printf("%d\n", time);
    return 0;
}
