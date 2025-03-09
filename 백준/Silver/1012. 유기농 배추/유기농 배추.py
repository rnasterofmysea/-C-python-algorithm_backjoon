from collections import deque

# 방향 벡터 (상, 하, 좌, 우)
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(y, x, farm, visited, M, N):
    queue = deque([(y, x)])
    visited[y][x] = 1  # 방문 처리

    while queue:
        cy, cx = queue.popleft()

        for i in range(4):  # 네 방향 탐색
            ny = cy + dy[i]
            nx = cx + dx[i]

            if 0 <= nx < M and 0 <= ny < N and farm[ny][nx] == 1 and visited[ny][nx] == 0:
                queue.append((ny, nx))
                visited[ny][nx] = 1  # 방문 처리

def count_worms(M, N, K, positions):
    # 배추밭 초기화
    farm = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]

    # 배추 위치 설정
    for x, y in positions:
        farm[y][x] = 1  # (x, y) 좌표 주어지므로 y, x 순서로 배치

    count = 0
    for y in range(N):
        for x in range(M):
            if farm[y][x] == 1 and visited[y][x] == 0:
                bfs(y, x, farm, visited, M, N)
                count += 1  # 배추 군집 하나 추가

    return count

# 입력
T = int(input())  # 테스트 케이스 개수
for _ in range(T):
    M, N, K = map(int, input().split())  # 가로, 세로, 배추 개수
    positions = [tuple(map(int, input().split())) for _ in range(K)]  # 배추 위치
    print(count_worms(M, N, K, positions))