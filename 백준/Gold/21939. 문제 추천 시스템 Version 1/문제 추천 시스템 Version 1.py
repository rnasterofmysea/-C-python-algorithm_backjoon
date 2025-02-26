import sys
import heapq

input = sys.stdin.readline

max_heap = []  # 최대 힙 (난이도 높은 문제 찾기)
min_heap = []  # 최소 힙 (난이도 낮은 문제 찾기)
valid = {}  # 문제 유효성 저장 (P -> L)
problem_set = set()  # (L, P) 형태 저장 (유효성 확인용)

N = int(input().strip())
for _ in range(N):
    P, L = map(int, input().strip().split())
    heapq.heappush(min_heap, (L, P))  # 최소 힙: 난이도 기준 정렬
    heapq.heappush(max_heap, (-L, -P))  # 최대 힙: 난이도 내림차순 정렬
    valid[P] = L  # 문제 유효성 저장
    problem_set.add((L, P))  # 문제 추가

M = int(input().strip())
for _ in range(M):
    prompt = input().strip().split()

    if prompt[0] == "recommend":
        """
        가장 어려운 문제 또는 쉬운 문제 출력
        """
        if prompt[1] == "1":
            # 가장 어려운 문제 찾기 (유효한 문제만 유지)
            while max_heap and (-max_heap[0][0], -max_heap[0][1]) not in problem_set:
                heapq.heappop(max_heap)  # 유효하지 않은 문제 제거
            print(-max_heap[0][1])  # P 출력
        else:
            # 가장 쉬운 문제 찾기 (유효한 문제만 유지)
            while min_heap and (min_heap[0][0], min_heap[0][1]) not in problem_set:
                heapq.heappop(min_heap)  # 유효하지 않은 문제 제거
            print(min_heap[0][1])  # P 출력

    elif prompt[0] == "add":
        """
        새로운 문제 추가
        """
        P, L = int(prompt[1]), int(prompt[2])
        heapq.heappush(min_heap, (L, P))
        heapq.heappush(max_heap, (-L, -P))
        valid[P] = L  # 문제 추가
        problem_set.add((L, P))  # 문제 추가

    elif prompt[0] == "solved":
        """
        특정 문제를 푼 것으로 처리
        """
        P = int(prompt[1])
        if P in valid:
            L = valid[P]  # 해당 문제의 난이도를 가져옴
            del valid[P]  # 문제 삭제
            problem_set.remove((L, P))  # 문제를 유효 목록에서 제거
