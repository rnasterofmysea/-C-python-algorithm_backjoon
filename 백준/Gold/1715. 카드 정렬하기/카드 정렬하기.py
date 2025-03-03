import sys
import heapq

N = int(input())

if N == 0:
    print(0)
    exit()

heap = []
for _ in range(N):
    heapq.heappush(heap, int(input()))

result = 0
while len(heap) > 1:  # 힙에 원소가 하나 남을 때까지 진행
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    sum_ab = a + b
    result += sum_ab
    heapq.heappush(heap, sum_ab)

print(result)
