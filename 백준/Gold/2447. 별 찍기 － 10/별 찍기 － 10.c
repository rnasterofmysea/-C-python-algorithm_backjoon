/*
전체 크기 N

기저조건
N이 3일 경우 해당 모양 출력

0 ~ N /3 > 줄어든 그대로 출력

N /3 ~ N * 2 / 3 > 중간이 비어야함

N / 3 ~ N > 줄어든 그대로 출력
*/

#include <stdio.h>
#include <string.h> // memset 사용을 위해 추가

#define MAX 2188
char arry[MAX][MAX];

void recursion(int x, int y, int len){
    //기저 조건
    if(len == 1){
        arry[x][y] = '*';
        return;
    }
    int new_len = len/3;
    for(int i = 0; i < 3 ; i ++){
        for(int j = 0; j < 3; j ++){
            if(i == 1 && j == 1){
                continue;
            } else{
                recursion(x + j * new_len, y + i * new_len, new_len);
            }
        }
    }
    
};

int main() {
    int N = 0;
    scanf("%d", &N);
    memset(arry, ' ', sizeof(arry));
    recursion(0,0,N);

    for(int i = 0 ; i < N; i++){
        arry[i][N] = '\0'; // 각 행의 끝에 null 문자 추가
        printf("%s\n", arry[i]);
    }
    return 0;
}