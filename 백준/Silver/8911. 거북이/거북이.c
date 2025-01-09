#include <stdio.h>
#include <string.h>
/*
{{0,-1},{1,0},{0,1},{-1,0}}

0,-1 > 왼쪽으로 회전 시 ?-1,0 > 한번더 > 0, 1 > 1, 0 > 0, -1
     > 오른쪽 회전 시  > 1, 0 >         1,0 >  0,1 > -1,0 
*/

int N = 0;

int main() {

    int direction[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
    scanf("%d", &N);
    
    for(int i = 0; i < N; i ++){
        int current[2] = {0,0};
        int current_dir = 0;
        char prompt[501];
        int history[500][2];
        int move_count = 0;
        scanf("%s", prompt);
        int len = strlen(prompt);
        for(int j = 0; j < len; j ++){
            if(prompt[j] == 'L'){
                current_dir -= 1;
                if(current_dir <0){
                    current_dir += 4;
                }
            }else if(prompt[j] == 'R'){
                current_dir +=1;
                if(current_dir > 3){
                    current_dir -= 4;
                }
            }else if(prompt[j] == 'F'){
                current[0] = current[0] + direction[current_dir][0];
                current[1] = current[1] + direction[current_dir][1];
                history[move_count][0] = current[0];
                history[move_count][1] = current[1];
                move_count ++;
            } else if(prompt[j] == 'B'){
                current[0] = current[0] + direction[(current_dir + 2) % 4][0];
                current[1] = current[1] + direction[(current_dir + 2) % 4][1];
                history[move_count][0] = current[0];
                history[move_count][1] = current[1];
                move_count ++;
            }
        }
        int min_x = 0, min_y = 0, max_x = 0 , max_y = 0;

        for(int x = 0 ; x < move_count; x ++){
            if(history[x][0] > 0 && history[x][0] > max_x){
                max_x = history[x][0];
            } else if(history[x][0] < 0 && history[x][0] < min_x){
                min_x = history[x][0];
            }

            if(history[x][1] > 0 && history[x][1] > max_y){
                max_y = history[x][1];
            } else if(history[x][1] < 0 && history[x][1] < min_y){
                min_y = history[x][1];
            }
        }
        int result = (max_x - min_x) * (max_y - min_y);
        printf("%d\n", result);        
    }
}