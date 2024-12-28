/*
BOJ_2630_색종이 만들기
https://www.acmicpc.net/problem/2630

*/

#include <stdio.h>
#define MAX 128;

int paper[128][128];
int white_count = 0;
int blue_count = 0;


void count(int color){
    if(color){
        blue_count++;
    } else{
        white_count++;
    }
};
void recursion(int x, int y, int size){
    // 종료조건(base case)
    if(size == 1){
        count(paper[x][y]);
        return;
    }

    //재귀조건(recursion case)
    int current = paper[x][y];
    int temp = 0;
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(paper[i][j] == current){
                continue;
            } else{
                temp = 1;
                break;
            }
        }
        if(temp){
            break;
        }
    }
    if(temp == 0){
        count(current);
        return;
    } else{
        int new_size = size / 2;
        for(int i = 0; i < 2; i ++){
            for(int j = 0; j < 2; j++){
                recursion(x + i * new_size , y + j * new_size, new_size);
            }
        }
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        for(int j = 0 ; j < N; j ++){
            scanf("%d", &paper[i][j]);
        }
    }

    recursion(0, 0,N);
    printf("%d\n", white_count);
    printf("%d\n", blue_count);
    
    return 0;
}