#include <stdio.h>

int N; // 숫자 개수
int numbers[11]; // 숫자 배열
int operators[4]; // +, -, *, / 연산자의 개수
int MAX = -1000000000; // 최댓값 초기화
int MIN = 1000000000;  // 최솟값 초기화

// DFS 탐색 함수
void dfs(int depth, int result) {
    if (depth == N) {
        // 모든 연산을 끝낸 경우 결과 갱신
        if (result > MAX) MAX = result;
        if (result < MIN) MIN = result;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--; // 연산자 사용
            int next_result = result;

            // 연산 수행
            if (i == 0) next_result += numbers[depth];          // 덧셈
            else if (i == 1) next_result -= numbers[depth];     // 뺄셈
            else if (i == 2) next_result *= numbers[depth];     // 곱셈
            else if (i == 3) {                                  // 나눗셈
                if (next_result < 0) 
                    next_result = -(-next_result / numbers[depth]);
                else 
                    next_result /= numbers[depth];
            }

            dfs(depth + 1, next_result); // 다음 단계로 이동
            operators[i]++; // 연산자 복구
        }
    }
}

int main() {
    // 입력 처리
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", &operators[i]); // 각 연산자의 개수
    }

    dfs(1, numbers[0]); // 첫 번째 숫자를 기준으로 DFS 시작

    // 결과 출력
    printf("%d\n", MAX);
    printf("%d\n", MIN);

    return 0;
}
