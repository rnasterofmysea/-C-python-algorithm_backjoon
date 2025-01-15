#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    
    long long prev1 = 0, prev2 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    
    printf("%lld\n", (n == 1 ? prev2 : current));
    return 0;
}
