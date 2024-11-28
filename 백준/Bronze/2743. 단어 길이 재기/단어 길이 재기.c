#include <stdio.h>
#include <string.h>
int main(void) {
    char line[101]; // 한 줄의 최대 길이 + NULL 문자
    scanf("%s", line);
    printf("%lu", strlen(line));
    return 0;
}
