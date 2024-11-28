

#include <stdio.h>

int main(void) {
    char line[101]; // 한 줄의 최대 길이 + NULL 문자

    // EOF까지 반복
    while (fgets(line, sizeof(line), stdin) != NULL) {
        printf("%s", line); // 입력받은 줄을 그대로 출력
    }

    return 0;
}
