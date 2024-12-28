#include <stdio.h>
#include <string.h>

#define MAX 2187
char arry[MAX][MAX];

// 재귀적으로 별 찍기 함수
void recursion(int x, int y, int len) {
    // 기저 조건
    if (len == 1) {
        arry[y][x] = '*';
        return;
    }

    int new_len = len / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // 중간 부분은 비워둠
            if (i == 1 && j == 1) {
                continue;
            }
            // 나머지 부분에 대해 재귀 호출
            recursion(x + j * new_len, y + i * new_len, new_len);
        }
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    // 배열 초기화 (공백으로 채움)
    memset(arry, ' ', sizeof(arry));

    // 재귀 호출로 별 찍기
    recursion(0, 0, N);

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            putchar(arry[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
