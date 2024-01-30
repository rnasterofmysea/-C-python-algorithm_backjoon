import sys
from itertools import permutations

n = int(sys.stdin.readline().strip())
values = list(map(int,sys.stdin.readline().rstrip().split()))
answer = 0
for p in permutations(values):
    total = 0
    for i in range(n-1):
        total += abs(p[i] - p[i+1])

    if answer < total:
        answer = total
print(answer)
