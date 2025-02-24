import sys
import heapq

input = sys.stdin.readline

T = int(input().strip())  # 테스트 케이스 개수

for _ in range(T):
    K = int(input().strip())  # 연산 개수
    
    max_heap = []  # 최대 힙 (음수로 저장)
    min_heap = []  # 최소 힙
    valid = {}  # 삭제된 값 체크용 딕셔너리

    for _ in range(K):
        cmd, num = input().strip().split()
        num = int(num)

        if cmd == "I":  # 삽입 연산
            heapq.heappush(max_heap, -num)  # 최대 힙 (음수 저장)
            heapq.heappush(min_heap, num)   # 최소 힙 (그대로 저장)
            valid[num] = valid.get(num, 0) + 1  # 값 추가 (유효성 체크)

        elif cmd == "D":
            if num == 1:  # 최대값 삭제
                while max_heap:
                    max_val = -heapq.heappop(max_heap)
                    if valid.get(max_val, 0) > 0:
                        valid[max_val] -= 1
                        break

            elif num == -1:  # 최소값 삭제
                while min_heap:
                    min_val = heapq.heappop(min_heap)
                    if valid.get(min_val, 0) > 0:
                        valid[min_val] -= 1
                        break

    while max_heap and valid.get(-max_heap[0], 0) == 0:
        heapq.heappop(max_heap)

    while min_heap and valid.get(min_heap[0], 0) == 0:
        heapq.heappop(min_heap)

    if not max_heap or not min_heap:
        print("EMPTY")
    else:
        print(-max_heap[0], min_heap[0])  # 최대값, 최소값 출력
