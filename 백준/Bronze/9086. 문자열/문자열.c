#include <stdio.h>
#include <string.h>

int main(void) {
    int test_num = 0;   // 테스트 케이스 개수
    scanf("%d", &test_num);

    for (int i = 0; i < test_num; i++) {
        char texts[1001];    // 문자열 저장 공간
        scanf("%s", texts);  // 문자열 입력

        // 첫 번째 문자와 마지막 문자 출력
        int len = strlen(texts); // 문자열 길이 계산
        printf("%c%c\n", texts[0], texts[len - 1]);
    }

    return 0;
}
