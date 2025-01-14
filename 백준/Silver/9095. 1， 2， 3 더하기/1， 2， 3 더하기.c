/*
C_BOJ_9095_1,2,3더하기
https://www.acmicpc.net/problem/9095

1. 테이블 생성
    : 경우의 수를 저장하는 1차원 배열
2. 점화식 생성
    F(n) = F(n-1) + F(n-2) + F(n-3)  
3. 초기값 n = 1 / n = 2 / n = 3
*/

#include <stdio.h>
#define MAX 11
int dp_table[MAX+1] = {0};

void create_table(){
    dp_table[1] = 1;
    dp_table[2] = 2;
    dp_table[3] = 4;

    for(int i = 4; i <= MAX; i ++){
            dp_table[i] = dp_table[i-1] + dp_table[i-2]+ dp_table[i-3];
    }
};

int main() {

    create_table();
    
    int T = 0;
    scanf("%d", &T);

    for(int i = 0 ; i < T; i ++){
        int value = 0;
        scanf("%d", &value);
        printf("%d\n", dp_table[value]);
    }
    return 0;
}