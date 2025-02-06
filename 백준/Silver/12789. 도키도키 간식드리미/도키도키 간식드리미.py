from collections import deque

# 입력 처리
N = int(input())
line = deque(map(int, input().split()))

# 변수 초기화
stack = []
current = 1  # 현재 간식을 받을 순서 번호

# 시뮬레이션 시작
while line or stack:
    # 줄에서 간식을 받을 수 있는 경우
    if line and line[0] == current:
        line.popleft()
        current += 1
    # 스택에서 간식을 받을 수 있는 경우
    elif stack and stack[-1] == current:
        stack.pop()
        current += 1
    # 줄에서 간식을 받을 수도, 스택에서 받을 수도 없는 경우
    else:
        if line:
            stack.append(line.popleft())
        else:
            break

# 결과 출력
if current > N:
    print("Nice")
else:
    print("Sad")
