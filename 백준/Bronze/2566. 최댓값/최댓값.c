#include <stdio.h>

int main(){

    int index, row, col = 0;
    int MAX = -1;
    for(int i = 0; i < 9; i++){
        for(int j = 0 ; j < 9 ; j ++){
            scanf("%d" , &index);
            if(MAX < index){
                MAX = index;
                row = i+1;
                col = j+1;
            }
        }
    }
    printf("%d\n%d %d", MAX, row, col);
    return 0;
}
