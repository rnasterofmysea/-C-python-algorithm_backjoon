#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp_table[1001]; // 각 위치에서의 증가 부분 수열 길이를 저장
int values[1001];

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &values[i]);
        dp_table[i] = 1; // 초기화: 최소 길이는 자기 자신만 포함
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (values[j] < values[i]) {
                dp_table[i] = MAX(dp_table[i], dp_table[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 1; i <= n; i++) {
        max_len = MAX(max_len, dp_table[i]);
    }

    printf("%d\n", max_len);
    return 0;
}
