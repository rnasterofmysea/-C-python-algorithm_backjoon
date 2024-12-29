/*
전체 크기 N (2의 제곱수, 1<= N <= 64)

모두 0 이면 0 / 1이면 1
아닐경우 4등분 등분이 나뉠 때마다 "(" ")" 추가
*/
#include <stdio.h>
#define MAX 64
char arry[64][65];

void recursion(int x, int y,int len){
    if(len == 1){
        printf("%c", arry[y][x]);
        return;
    }
    char current = arry[y][x];
    //printf("%d c: %c\n", count++, current);
    int temp = 0;
    
    for(int i = y; i < len + y; i++){
        for(int j = x; j < len + x; j++){
            if(current != arry[i][j]){
                temp = 1;
                break;
            }
        }
        if(temp==1){break;}
    }
    if(temp){
        printf("(");
        recursion(x,y,len/2);
        recursion(x+len/2,y,len/2);
        recursion(x,y+len/2,len/2);
        recursion(x+len/2,y+len/2,len/2);
        printf(")");
        
    }else{
        printf("%c",current);
        return;
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    for(int i = 0 ; i < N; i ++){
        scanf("%s", arry[i]);
    }

    recursion(0,0, N);
    return 0;
}