import sys

K = int(sys.stdin.readline().strip())

stack = []
top = -1
for i in range(K):
    value = int(sys.stdin.readline().strip())
    if value == 0 & top != -1:
        stack.pop()
        top -= 1
    else:
        top += 1
        stack.append(value)
        

print(sum(stack))
