#include <stdio.h>
#include <math.h>

// 하노이 탑 재귀 함수
void hanoi(int n, int from, int to, int temp) {
    if (n == 1) {
        printf("%d %d\n", from, to); // 원판 1개를 옮기는 경우
        return;
    }
    // n-1개를 from에서 temp로 옮김
    hanoi(n - 1, from, temp, to);
    // 가장 큰 원판을 from에서 to로 옮김
    printf("%d %d\n", from, to);
    // n-1개를 temp에서 to로 옮김
    hanoi(n - 1, temp, to, from);
}

int main() {
    int n;
    scanf("%d", &n); // 원판 개수 입력

    // 최소 이동 횟수 출력
    printf("%d\n", (int)pow(2, n) - 1);

    // 하노이 탑 이동 출력
    hanoi(n, 1, 3, 2);

    return 0;
}
