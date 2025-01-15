#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp_table[301][2] = {0};
int value[301];

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    // 초기화
    dp_table[1][0] = value[1];
    dp_table[2][0] = value[2];
    dp_table[2][1] = value[1] + value[2];

    // 점화식 계산
    for (int i = 3; i <= n; i++) {
        dp_table[i][0] = MAX(dp_table[i-2][0], dp_table[i-2][1]) + value[i];
        dp_table[i][1] = dp_table[i-1][0] + value[i];
    }

    // 결과 출력
    printf("%d", MAX(dp_table[n][0], dp_table[n][1]));
    return 0;
}
