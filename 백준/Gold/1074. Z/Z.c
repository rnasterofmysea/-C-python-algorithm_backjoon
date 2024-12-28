/*
BOJ_1074_Z
https://www.acmicpc.net/problem/1074
*/

#include <stdio.h>

int count = 0;

void recursion(int x, int y, int size, int r, int c) {
    // Base case: 배열 크기가 1일 때
    if (size == 1) {
        if (x == c && y == r) {
            return;
        }
    }

    // 배열 크기를 절반으로 나눔
    int new_size = size / 2;

    // 반복문으로 사분면 탐색
    for (int i = 0; i < 2; i++) {      // 행 방향(상하)
        for (int j = 0; j < 2; j++) {  // 열 방향(좌우)
            int nx = x + j * new_size; // 새로운 x 좌표
            int ny = y + i * new_size; // 새로운 y 좌표

            // 현재 사분면에 r, c가 속하는지 확인
            if (ny <= r && r < ny + new_size && nx <= c && c < nx + new_size) {
                count += (i * 2 + j) * new_size * new_size; // 사분면 카운트 추가
                recursion(nx, ny, new_size, r, c);         // 해당 사분면으로 재귀 호출
                return; // 탐색 완료 후 반환
            }
        }
    }
}

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);

    int size = 1 << N; // 배열 크기: 2^N
    recursion(0, 0, size, r, c);

    printf("%d", count);
    return 0;
}
