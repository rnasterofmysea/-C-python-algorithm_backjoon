/*
BOj_1759_암호만들기
https://www.acmicpc.net/problem/1759
*/

#include <stdio.h>
#define MAX 15
int L, C;
char input_arry[MAX+1];
char arry[MAX+1];
int visited[MAX];

void selectSort(int C){
    char min = 0;
    for(int i = 0 ; i < C - 1; i++){
        min = i;
        for(int j = i+1 ; j <C; j++){
            if(input_arry[min] > input_arry[j]){
                min = j;
            }
        }
        if(min != i){
            char temp = input_arry[i];
            input_arry[i] = input_arry[min];
            input_arry[min] = temp;
        }
    }
}

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void dfs(int depth , int vowels, int consonants){
    if(depth == L && vowels >= 1 && consonants >= 2){
        for(int i = 0; i < L; i++){
            printf("%c", arry[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 0; i < C; i++){
        if(!visited[i]){
            if (depth > 0 && arry[depth - 1] > input_arry[i]) {
                continue;
            }

            arry[depth] = input_arry[i];
            visited[i] = 1;

            if (isVowel(input_arry[i])) {
                dfs(depth + 1, vowels + 1, consonants);
            } else {
                dfs(depth + 1, vowels, consonants + 1);
            }

            visited[i] = 0;
        }
    }
    
}

int main() {
    scanf("%d %d", &L, &C);
    for(int i = 0 ; i < C ; i ++){
        scanf(" %c", &input_arry[i]);
    }

    selectSort(C);

    dfs(0,0, 0);
    
    return 0;
}