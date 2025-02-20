import sys

def recursion(N):
    # Base Case: N이 0이면 "-" 하나를 반환
    if N == 0:
        return "-"

    # 이전 단계(N-1)의 칸토어 집합 생성
    prev = recursion(N - 1)

    # 공백 추가 (가운데 부분 제거)
    space = " " * (3 ** (N - 1))

    # 새로운 칸토어 집합 = 이전 집합 + 공백 + 이전 집합
    return prev + space + prev

# 입력 받기
input = sys.stdin.readline
while(True):
    try:
        N = int(input().strip())

        # 결과 출력
        print(recursion(N))
    except:
        break