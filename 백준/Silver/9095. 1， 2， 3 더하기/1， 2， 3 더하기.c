#include <stdio.h>

/*

1. dp_table 생성
    > 저장할 정보: 경우의 수
2. 점화식
    F(n) = F(n-1) + F(n-2) + F(n-3)
    
    F(1) = 1
    F(2) = 2 (1 1, 2)
    F(3) = 4 (1,1,1 / 1,2 / 2,1 / 3)
    F(4) = 1, 3 / 1, 1, 2 / 2, 2 / 1,1,1,1 / 1,2,1,1/2,1,1,1/3,1 
3. 초기값

*/
int main() {
    int dp_table[11];
    int T = 0;
    scanf("%d", &T);

    dp_table[1] = 1;
    dp_table[2] = 2;
    dp_table[3] = 4;

    for(int i =4 ; i <= 11; i ++){
        dp_table[i] = dp_table[i-1] + dp_table[i-2] + dp_table[i-3];
        
    }
    for(int i = 0 ; i < T; i ++){
        int temp;
        scanf("%d", &temp);
        printf("%d\n", dp_table[temp]);
    }

    return 0;
}