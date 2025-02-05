N = int(input())
buildings = [int(input()) for _ in range(N)]

stack = []
result = 0

for i in range(N):
    # 스택에 있는 빌딩들이 현재 빌딩보다 작으면 스택에서 제거
    while stack and stack[-1] <= buildings[i]:
        stack.pop()
    
    # 스택에 남아있는 빌딩들은 현재 빌딩이 볼 수 있는 빌딩들
    result += len(stack)
    
    # 현재 빌딩을 스택에 추가
    stack.append(buildings[i])

print(result)
