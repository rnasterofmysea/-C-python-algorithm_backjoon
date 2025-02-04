/*
C_BOJ_18870_좌표압축
https://www.acmicpc.net/problem/18870
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int arry[MAX] = {0};
int unique[MAX] = {0};
int copy[MAX] = {0};

int compare(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    if (int_a > int_b) return 1;
    if (int_a < int_b) return -1;
    return 0;
}
int main() {
    int N = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arry[i]);    
    }
    for(int i = 0 ; i < N; i ++){
        copy[i] = arry[i];
    }
    qsort(arry, N, sizeof(int), compare);
    
    int index = 0;
    unique[index++] = arry[0];
    for (int i = 1; i < N; i++) {
        if (arry[i] != arry[i - 1]) {
            unique[index++] = arry[i];
        }
    }

    for(int i = 0; i< N; i ++){
        int target = copy[i];
        int start = 0;
        int end = index-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == unique[mid]){
                printf("%d ", mid);
                break;
            } else if(target < unique[mid]){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
    }
    return 0;
}