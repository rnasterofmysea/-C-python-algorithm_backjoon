/*
BOJ_6603_로또
https://www.acmicpc.net/problem/6603
*/

#include <stdio.h>
#include <stdlib.h>
int arry[13];
int N = 0;
int com[6];

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}


void combination(int depth, int idx){
    if(depth == 6){
        for(int i = 0; i < 6; i ++){
            printf("%d ", com[i]);
        }
        printf("\n");
        return;
    }

    for(int i = idx; i < N; i ++){
        com[depth] = arry[i];
        combination(depth + 1, i + 1);
    }
    
}


int main() {
    while(1){
        scanf("%d", &N);
        if(N == 0){
            break;
        }
        for(int i = 0; i < N; i ++){
            scanf("%d", &arry[i]);
        }
        // 오름차순
        // 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
        qsort(arry, N, sizeof(int), compare);
        // 조합
        combination(0, 0);
        printf("\n");
        
    }
    
    return 0;
}