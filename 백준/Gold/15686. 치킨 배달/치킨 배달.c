#include <stdio.h>
#include <stdlib.h>

int N, M;                  // 도시 크기, 남길 치킨집의 개수
int map[50][50];           // 도시 맵
int houses[100][2];        // 집 좌표
int house_count = 0;       // 집 개수
int chicken_count = 0;     // 치킨집 개수
int chickens[13][2];       // 치킨집 좌표
int selected[13] = {0};    // 선택된 치킨집 표시
int min_distance = 1e9;    // 최소 치킨 거리

// 거리 계산 함수
int calculate_chicken_distance() {
    int total_distance = 0;
    for (int i = 0; i < house_count; i++) {
        int hx = houses[i][0];
        int hy = houses[i][1];
        int min_dist = 1e9;
        for (int j = 0; j < chicken_count; j++) {
            if (selected[j]) {
                int cx = chickens[j][0];
                int cy = chickens[j][1];
                int dist = abs(hx - cx) + abs(hy - cy);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        total_distance += min_dist;
    }
    return total_distance;
}

// 백트래킹으로 치킨집 조합 선택
void dfs(int idx, int cnt) {
    if (cnt == M) {
        // 현재 선택된 치킨집으로 치킨 거리 계산
        int distance = calculate_chicken_distance();
        if (distance < min_distance) {
            min_distance = distance;
        }
        return;
    }

    for (int i = idx; i < chicken_count; i++) {
        if (!selected[i]) {
            selected[i] = 1;
            dfs(i + 1, cnt + 1);
            selected[i] = 0;
        }
    }
}

int main() {
    // 입력 받기
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                houses[house_count][0] = i;
                houses[house_count][1] = j;
                house_count++;
            } else if (map[i][j] == 2) {
                chickens[chicken_count][0] = i;
                chickens[chicken_count][1] = j;
                chicken_count++;
            }
        }
    }

    // 백트래킹으로 최소 치킨 거리 계산
    dfs(0, 0);

    // 결과 출력
    printf("%d\n", min_distance);
    return 0;
}
