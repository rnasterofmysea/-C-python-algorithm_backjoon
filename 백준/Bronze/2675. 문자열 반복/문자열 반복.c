#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int count = 0;
    scanf("%d", &count);
    getchar(); // 버퍼에 남은 개행 문자 제거

    for (int i = 0; i < count; i++) {        
        char *input = NULL;
        size_t buffer_size = 0;
        getline(&input, &buffer_size, stdin);

        // 입력 문자열 끝에 있는 개행 문자 제거
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // 정수와 문자열 분리
        char *ptr = strtok(input, " ");
        int repeat = atoi(ptr);  // 반복 횟수 변환
        ptr = strtok(NULL, " "); // 반복할 문자열

        // 결과 저장용 배열 선언 및 초기화
        size_t output_len = strlen(ptr) * repeat + 1;
        char output[output_len];
        memset(output, 0, output_len); // 배열 초기화

        // 문자열 생성
        int flag = 0;
        for (size_t z = 0; z < strlen(ptr); z++) {
            for (int y = 0; y < repeat; y++) {
                output[flag++] = ptr[z];
            }
        }
        output[flag] = '\0'; // 널 문자 추가

        // 결과 출력
        printf("%s\n", output);
        free(input);
    }

    return 0;
}
