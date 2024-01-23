K, N = map(int, input().split())

array = list(range(1, K + 1))
answer = []

index = 0
while array:
    index = (index + N - 1) % len(array)
    answer.append(array.pop(index))

print("<", end='')
print(*answer, sep=', ', end='')
print(">", end='')
