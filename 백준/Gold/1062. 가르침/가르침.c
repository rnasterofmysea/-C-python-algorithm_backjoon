#include <stdio.h>
#include <string.h>

// 단어 개수 N, 글자 개수 K
int N, K;
int count = 0;
char lines[50][16];
int invalid_line[50] = {0};
int alphabet_visited[26] = {0};

void alphabet_combination(int depth, int start) {
    if (depth == K) {
        int temp_count = 0;
        for (int i = 0; i < N; i++) {
            if (!invalid_line[i]) {
                int len = strlen(lines[i]);
                int flag = 1; // 단어를 읽을 수 있다고 가정
                for (int j = 4; j < len - 4; j++) { // "anta"와 "tica" 제외
                    if (!alphabet_visited[lines[i][j] - 'a']) {
                        flag = 0; // 읽을 수 없는 글자 발견
                        break;
                    }
                }
                if (flag) {
                    temp_count++;
                }
            }
        }
        if (temp_count > count) {
            count = temp_count;
        }
        return;
    }

    for (int i = start; i < 26; i++) {
        if (!alphabet_visited[i]) {
            alphabet_visited[i] = 1;
            alphabet_combination(depth + 1, i + 1);
            alphabet_visited[i] = 0;
        }
    }
}

int main() {
    char start[5] = "anta";
    char end[5] = "tica";
    char min_alphabets[6] = "antic"; // 최소 필수 알파벳

    scanf("%d %d", &N, &K);

    // 글자 개수가 5 미만일 경우
    if (K < 5) {
        printf("0\n");
        return 0;
    }

    // 필수 알파벳 방문 처리
    for (int i = 0; i < 5; i++) {
        alphabet_visited[min_alphabets[i] - 'a'] = 1;
    }

    // 단어 입력 및 유효성 검사
    for (int i = 0; i < N; i++) {
        scanf("%s", lines[i]);
        int len_line = strlen(lines[i]);
        for (int j = 0; j < 4; j++) {
            if (lines[i][j] != start[j] || lines[i][len_line - 4 + j] != end[j]) {
                invalid_line[i] = 1;
                break;
            }
        }
    }

    // 알파벳 조합 생성
    alphabet_combination(5, 0);

    // 결과 출력
    printf("%d\n", count);
    return 0;
}
