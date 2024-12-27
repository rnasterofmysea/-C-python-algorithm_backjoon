#include <stdio.h>
#include <stdlib.h>

// 전역 변수
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
void recursion(int **paper, int x, int y, int size) {
    int current = paper[x][y];
    int same = 1;

    // 현재 영역이 모두 같은 숫자인지 확인
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
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
            recursion(paper, x + i * new_size, y + j * new_size, new_size);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // 2차원 배열 동적 할당
    int **paper = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        paper[i] = (int *)malloc(N * sizeof(int));
    }

    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    // 재귀 호출
    recursion(paper, 0, 0, N);

    // 결과 출력
    printf("%d\n", minus_count);
    printf("%d\n", zero_count);
    printf("%d\n", one_count);

    // 동적 메모리 해제
    for (int i = 0; i < N; i++) {
        free(paper[i]);
    }
    free(paper);

    return 0;
}
