/*
C_BOJ_12789_도키도키 간식드리미
http://acmicpc.net/problem/12789

스택에 값을 넣던지 통과 시키던지 번호순서대로
입력값이 N이라면

for(int i = 0 ; i < 5; i ++)
    temp = 0
    for(int j = start ; j < 5; j ++)
            대기열의 값이 i가 아니라면 stack에 push
            대기열의 값이 i라면 pass
                start = j
                temp = 1
                break
    if temp == 0
        팝으로 꺼내기
        temp = 1

    temp == 0
        return
    
*/

#include <stdio.h>

int main() {
    int N = 0;
    int arry[1000] = {0};
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d", &arry[i]);
    }

    int start = 0;
    int stack[1000] = {0};
    int top = -1;
    for(int i = 1; i <= N; i++){
        int target = i;
        int temp = 0;
        for(int j = start; j < N; j++){
            if(target != arry[j]){
                stack[++top] = arry[j];
            } else {
                start = j+1;
                temp = 1;
                break;
            }
        }
        if(temp == 0){
            while(0 <= top){
                if(target != stack[top]){
                    top --;
                } else{ temp = 1; break;}
            }
        }

        if(temp == 0){
            printf("Sad");
            return 0;
        }
    }
    printf("Nice");
    return 0;
}