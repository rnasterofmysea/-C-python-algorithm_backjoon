N = int(input())
arry = list(map(int, input().split()))
start = 0
stack = []
for i in range(1,N):
    target = i
    temp = 0
    for j in range(start, N):
        if target != arry[j] :
            stack.append(arry[j])
        else:
            start = j+1
            temp = 1
            break
    if temp == 0:
        while(stack):
            if target != stack[-1]:
                stack.pop()
            else:
                temp = 1
                break
    if temp == 0:
        print("Sad")
        exit()

print("Nice")