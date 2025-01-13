#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct member {
    int index;      // 입력된 순서 저장
    char name[101]; // 이름
    int age;        // 나이
} member;

int compare(const void *a, const void *b) {
    const member *mem1 = (const member *)a;
    const member *mem2 = (const member *)b;

    // 나이를 기준으로 정렬
    if (mem1->age != mem2->age) {
        return mem1->age - mem2->age; // 나이 오름차순
    }

    // 나이가 같으면 입력 순서(index) 기준으로 정렬
    return mem1->index - mem2->index;
}

member members[100000]; // 멤버 배열

int main() {
    int N = 0;
    scanf("%d", &N);


    for (int i = 0; i < N; i++) {
        int temp_age;
        char temp_name[101];

        // 나이와 이름 입력
        scanf("%d %s", &temp_age, temp_name);

        // 멤버 초기화
        members[i].age = temp_age;
        strcpy(members[i].name, temp_name);
        members[i].index = i; // 입력 순서 저장
    }

    // 정렬
    qsort(members, N, sizeof(member), compare);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }

    return 0;
}
