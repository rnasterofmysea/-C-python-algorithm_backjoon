#include <stdio.h>
#include <string.h>

// 최대 단어 수와 알파벳 개수
int N, K;
char words[50][16];
int alphabet_visited[26];
int max_count = 0;

// 읽을 수 있는 단어 개수를 계산
int count_readable_words() {
    int readable_count = 0;
    for (int i = 0; i < N; i++) {
        int len = strlen(words[i]);
        int is_readable = 1;
        for (int j = 4; j < len - 4; j++) { // "anta"와 "tica" 제외
            if (!alphabet_visited[words[i][j] - 'a']) {
                is_readable = 0;
                break;
            }
        }
        if (is_readable) {
            readable_count++;
        }
    }
    return readable_count;
}

// 알파벳 조합을 생성하여 최대 단어 수를 계산
void combination(int depth, int start) {
    if (depth == K) {
        int current_count = count_readable_words();
        if (current_count > max_count) {
            max_count = current_count;
        }
        return;
    }

    for (int i = start; i < 26; i++) {
        if (!alphabet_visited[i]) {
            alphabet_visited[i] = 1;
            combination(depth + 1, i + 1);
            alphabet_visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);

    // 글자 수가 5 미만일 경우
    if (K < 5) {
        printf("0\n");
        return 0;
    }

    // 필수 알파벳 "antic" 설정
    alphabet_visited['a' - 'a'] = 1;
    alphabet_visited['n' - 'a'] = 1;
    alphabet_visited['t' - 'a'] = 1;
    alphabet_visited['i' - 'a'] = 1;
    alphabet_visited['c' - 'a'] = 1;

    // 단어 입력 및 "anta"와 "tica" 검증
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
        int len = strlen(words[i]);

        // 시작이 "anta"이고 끝이 "tica"인지 검증
        if (strncmp(words[i], "anta", 4) != 0 || strcmp(words[i] + len - 4, "tica") != 0) {
            i--; // 유효하지 않은 단어는 건너뜀
            N--; // 단어 수를 줄임
        }
    }

    // 알파벳 조합 생성
    combination(5, 0);

    // 최대 읽을 수 있는 단어 출력
    printf("%d\n", max_count);
    return 0;
}
