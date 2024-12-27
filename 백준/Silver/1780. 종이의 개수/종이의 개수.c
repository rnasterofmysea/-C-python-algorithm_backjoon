/*
BOJ_1780_종이의 개수
https://www.acmicpc.net/problem/1780
*/

#include <stdio.h>

// 최대 크기 정의
#define MAX_SIZE 2187  // 3^7, 문제에서 N은 최대 3^7 = 2187

// 전역 변수
int paper[MAX_SIZE][MAX_SIZE];
int zero_count = 0;
int one_count = 0;
int minus_count = 0;

// 카운팅 함수
void counting(int value) {
    if (value == 0) {
        zero_count++;
    } else if (value == 1) {
        one_count++;
    } else {
        minus_count++;
    }
}

// 재귀 함수
void recursion(int x_start, int x_end, int y_start, int y_end) {
    int current = paper[x_start][y_start];
    int same = 1;
    int size = x_end - x_start;

    // 현재 영역이 모두 같은 숫자인지 확인
    for (int i = x_start; i < x_end; i++) {
        for (int j = y_start; j < y_end; j++) {
            if (paper[i][j] != current) {
                same = 0;
                break;
            }
        }
        if (!same) break;
    }

    // 모두 같은 숫자라면 카운트하고 종료
    if (same) {
        counting(current);
        return;
    }

    // 모두 같은 숫자가 아니라면 9등분하여 재귀 호출
    int new_size = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recursion(x_start + i * new_size, x_start + (i + 1) * new_size,
                      y_start + j * new_size, y_start + (j + 1) * new_size);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    // 재귀 호출
    recursion(0, N, 0, N);

    // 결과 출력
    printf("%d\n", minus_count);
    printf("%d\n", zero_count);
    printf("%d\n", one_count);

    return 0;
}
