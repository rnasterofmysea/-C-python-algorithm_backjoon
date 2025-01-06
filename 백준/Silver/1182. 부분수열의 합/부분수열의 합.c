#include <stdio.h>

int N = 0;
int S = 0;
int arry[20];
int visited[20];
int current_arry[20];
int count = 0;
void dfs(int leaf, int depth, int idx){
    if(depth == leaf){
        
        int result = 0;
        for(int i = 0; i < leaf; i++){
            result += current_arry[i];
        }
        if(result == S){
            count ++;
        }
        return;
    }
    for(int i = idx; i < N; i ++){
        if(!visited[i]){
            visited[i] = 1;
            current_arry[depth] = arry[i];
            dfs(leaf, depth+1, i);
            visited[i] = 0;
        }
    }
};
int main() {
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i ++){
        scanf("%d",&arry[i]);
    }
    
    for(int i = 1; i <= N; i ++){
        dfs(i, 0, 0);
    }
    printf("%d", count);
    return 0;
}