#include <stdio.h>

#define MAX_DAYS 1000000

long prices[MAX_DAYS];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        // 주식 가격 입력
        for (int i = 0; i < n; i++) {
            scanf("%ld", &prices[i]);
        }

        // 뒤에서부터 최대값을 유지하며 최대 이익 계산
        long max_price = 0;
        long long profit = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > max_price) {
                max_price = prices[i];
            } else {
                profit += max_price - prices[i];
            }
        }

        printf("%lld\n", profit);
    }

    return 0;
}
