n = int(input())
sequence = [int(input()) for _ in range(n)]

stack = []
result = []
current = 1

for num in sequence:
    # 현재 숫자가 스택의 마지막 값보다 크면 push 작업 수행
    while current <= num:
        stack.append(current)
        result.append("+")
        current += 1
    
    # 스택의 마지막 값이 num과 같다면 pop 수행
    if stack[-1] == num:
        stack.pop()
        result.append("-")
    else:
        # 불가능한 수열인 경우
        print("NO")
        exit()

# 결과 출력
print("\n".join(result))
