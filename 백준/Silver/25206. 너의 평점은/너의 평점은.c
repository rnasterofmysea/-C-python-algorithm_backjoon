#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float grade_transit(char *grade) {
    if (!strcmp(grade, "A+")) {
        return 4.5;
    } else if (!strcmp(grade, "A0")) {
        return 4.0;
    } else if (!strcmp(grade, "B+")) {
        return 3.5;
    } else if (!strcmp(grade, "B0")) {
        return 3.0;
    } else if (!strcmp(grade, "C+")) {
        return 2.5;
    } else if (!strcmp(grade, "C0")) {
        return 2.0;
    } else if (!strcmp(grade, "D+")) {
        return 1.5;
    } else if (!strcmp(grade, "D0")) {
        return 1.0;
    } else {
        return 0.0; // "F" or invalid grades
    }
}

int main(void) {
    float tot_points = 0.0;
    float tot_grades = 0.0;

    for (int i = 0; i < 20; i++) {
        char *row = NULL;
        size_t buffer = 0;

        getline(&row, &buffer, stdin);

        // 입력 문자열 끝의 개행 문자 제거
        size_t len = strlen(row);
        if (len > 0 && row[len - 1] == '\n') {
            row[len - 1] = '\0';
        }

        // 데이터 분리
        char *name = strtok(row, " ");
        char *point = strtok(NULL, " ");
        char *grade = strtok(NULL, " ");

        // "P" 학점 무시
        if (grade[0] == 'P') {
            free(row);
            continue;
        }

        // 학점 계산
        float points = atof(point); // 학점
        float grade_value = grade_transit(grade); // 등급에 따른 점수

        tot_points += points;
        tot_grades += points * grade_value; // 학점 * 점수 누적

        free(row); // 메모리 해제
    }

    // 결과 출력
    printf("%.6f\n", tot_grades / tot_points);
    return 0;
}
