#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 원형 큐 초기화
    int *cqueue = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        cqueue[i] = i + 1; // 1부터 N까지 큐에 저장
    }

    int front = 0; // 큐의 시작 인덱스
    int len = N;   // 큐의 현재 크기
    int result = 0;

    for (int i = 0; i < M; i++) {
        int m_input;
        scanf("%d", &m_input);

        // 목표 값의 위치 찾기
        int l_count = 0;
        int r_count = 0;

        // 오른쪽 이동 횟수 계산
        int flag = front;
        while (cqueue[flag] != m_input) {
            flag = (flag + 1) % len;
            r_count++;
        }

        // 왼쪽 이동 횟수 계산
        flag = front;
        while (cqueue[flag] != m_input) {
            flag = (len + flag - 1) % len;
            l_count++;
        }

        // 이동 방향 결정 및 이동
        if (r_count <= l_count) {
            // 오른쪽 이동
            front = (front + r_count) % len;
            result += r_count;
        } else {
            // 왼쪽 이동
            front = (len + front - l_count) % len;
            result += l_count;
        }

        // 목표 값 제거 및 큐 크기 감소
        for (int j = front; j < len - 1; j++) {
            cqueue[j] = cqueue[(j + 1) % len];
        }
        len--;
        if (front == len) {
            front = 0; // 마지막 요소 제거 후, 큐 크기와 인덱스를 맞춤
        }
    }

    printf("%d", result);

    // 메모리 해제
    free(cqueue);

    return 0;
}
