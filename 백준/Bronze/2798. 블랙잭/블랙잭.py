import sys


total, value = map(int, sys.stdin.readline().rstrip().split())
numbers = list(map(int, sys.stdin.readline().rstrip().split()))
answer = 0

for t in range(0, total-2):
    x1 = numbers[t]
    for i in range(t + 1, total-1):
        x2 = numbers[i]
        for j in range(i+1, total):
            x3 = numbers[j]
            sub = x1 + x2 + x3
            if sub > answer and sub <= value:
                answer = sub

print(answer)
