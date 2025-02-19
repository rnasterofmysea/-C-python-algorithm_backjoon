import sys

input = sys.stdin.readline

M = int(input().strip())  # 교환 횟수
ball_position = 1  # 공은 처음에 1번 컵 아래에 있음

for _ in range(M):
    a, b = map(int, input().strip().split())
    # 공이 a번 컵에 있으면 b번으로 이동
    if ball_position == a:
        ball_position = b
    # 공이 b번 컵에 있으면 a번으로 이동
    elif ball_position == b:
        ball_position = a

print(ball_position)
