N = int(input())
arry = list(map(int, input().split()))
start = 0
stack = []

for i in range(1, N):
    target = i
    found = False

    # 배열에서 target 찾기
    for j in range(start, N):
        if target != arry[j]:
            stack.append(arry[j])
        else:
            start = j + 1
            found = True
            break

    # 스택에서 target 찾기
    if not found:
        while stack:
            if target == stack.pop():
                found = True
                break

    # target이 어디에도 없을 경우
    if not found:
        print("Sad")
        exit()

print("Nice")
