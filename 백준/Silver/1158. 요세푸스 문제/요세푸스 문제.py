import sys

K, N = map(int,sys.stdin.readline().rstrip().split())

array = list(range(1, K + 1))
answer = []

index = 0
while array:
    index = (index + N - 1) % len(array)
    answer.append(str(array.pop(index)))
print('<' + ', '.join(answer) + '>')
