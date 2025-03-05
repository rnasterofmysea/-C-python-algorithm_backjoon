"""
python_boj_1927_최소 힙
https://www.acmicpc.net/problem/1927
"""
import sys
import heapq
input = sys.stdin.readline

N = int(input().strip())

heap = []
for _ in range(N):
    temp = int(input().strip())
    if temp == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, temp)
    