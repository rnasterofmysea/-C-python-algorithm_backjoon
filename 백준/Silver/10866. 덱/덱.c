#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

// 덱 구조체 정의
typedef struct {
    int data[MAX_SIZE];
    int front;
    int back;
} Deque;

// 함수 선언
void init_deque(Deque* dq);
void push_front(Deque* dq, int value);
void push_back(Deque* dq, int value);
void pop_front(Deque* dq);
void pop_back(Deque* dq);
void size(Deque* dq);
void empty(Deque* dq);
void front(Deque* dq);
void back(Deque* dq);

int main() {
    int N;
    scanf("%d", &N);

    Deque dq;
    init_deque(&dq);

    char command[15];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            scanf("%d", &value);
            push_front(&dq, value);
        } else if (strcmp(command, "push_back") == 0) {
            scanf("%d", &value);
            push_back(&dq, value);
        } else if (strcmp(command, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(command, "pop_back") == 0) {
            pop_back(&dq);
        } else if (strcmp(command, "size") == 0) {
            size(&dq);
        } else if (strcmp(command, "empty") == 0) {
            empty(&dq);
        } else if (strcmp(command, "front") == 0) {
            front(&dq);
        } else if (strcmp(command, "back") == 0) {
            back(&dq);
        }
    }

    return 0;
}

// 덱 초기화
void init_deque(Deque* dq) {
    dq->front = MAX_SIZE / 2;
    dq->back = MAX_SIZE / 2;
}

// 앞쪽에 값을 추가
void push_front(Deque* dq, int value) {
    dq->data[--dq->front] = value;
}

// 뒤쪽에 값을 추가
void push_back(Deque* dq, int value) {
    dq->data[dq->back++] = value;
}

// 앞쪽 값을 제거하고 출력
void pop_front(Deque* dq) {
    if (dq->front == dq->back) {
        printf("-1\n");
    } else {
        printf("%d\n", dq->data[dq->front++]);
    }
}

// 뒤쪽 값을 제거하고 출력
void pop_back(Deque* dq) {
    if (dq->front == dq->back) {
        printf("-1\n");
    } else {
        printf("%d\n", dq->data[--dq->back]);
    }
}

// 덱 크기 출력
void size(Deque* dq) {
    printf("%d\n", dq->back - dq->front);
}

// 덱이 비어 있는지 확인
void empty(Deque* dq) {
    printf("%d\n", (dq->front == dq->back) ? 1 : 0);
}

// 앞쪽 값을 출력
void front(Deque* dq) {
    if (dq->front == dq->back) {
        printf("-1\n");
    } else {
        printf("%d\n", dq->data[dq->front]);
    }
}

// 뒤쪽 값을 출력
void back(Deque* dq) {
    if (dq->front == dq->back) {
        printf("-1\n");
    } else {
        printf("%d\n", dq->data[dq->back - 1]);
    }
}
