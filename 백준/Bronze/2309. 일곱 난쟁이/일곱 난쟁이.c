#include <stdio.h>
#include <stdlib.h>
int selected[7] = {0};
int midgets[9] = {0};

// 조합을 통해 합이 100인지 확인
void combination(int depth, int index) {
    if (depth == 7) {  // 선택한 7명의 합 계산
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += selected[i];
        }
        if (sum == 100) {  // 합이 정확히 100인 경우 출력
            for(int i = 0 ; i < 6; i ++){
                int min_index = i;
                for(int j = i + 1; j < 7; j++){
                    if(selected[j] < selected[min_index]){
                        min_index = j;
                    }
                }
                int temp = 0;
                temp = selected[i];
                selected[i] = selected[min_index];
                selected[min_index] = temp;
            }
            
            for (int i = 0; i < 7; i++) {
                printf("%d\n", selected[i]);
            }
            exit(0);
        }
        return;
    }

    for (int i = index; i < 9; i++) {
        selected[depth] = midgets[i];  // 현재 난쟁이 선택
        combination(depth + 1, i + 1);  // 다음 깊이로 이동
    }
}

int main() {
    // 9명의 난쟁이 입력
    for (int i = 0; i < 9; i++) {
        scanf("%d", &midgets[i]);
    }

    // 조합 생성
    combination(0, 0);

    return 0;
}
