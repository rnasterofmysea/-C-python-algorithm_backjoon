import sys

input = sys.stdin.readline

N = int(input().strip())

arry = []
for _ in range(N):
    temp = int(input().strip())
    arry.append(temp)

arry.sort()  # 원본 리스트 정렬

current = arry[0]
count = 1
max_count = 1
max_num = arry[0]

for i in range(1, N):
    if arry[i] == current:
        count += 1
    else:
        if count > max_count:
            max_count = count
            max_num = current
        current = arry[i]
        count = 1

# 마지막 원소에 대한 처리
if count > max_count:
    max_num = current

print(max_num)
