import sys
sys.setrecursionlimit(10**6)

# 메모이제이션을 위한 딕셔너리 초기화
memo = {0: 1}

def A(n, P, Q):
    if n in memo:
        return memo[n]
    # 재귀적으로 A(n) 계산
    memo[n] = A(n // P, P, Q) + A(n // Q, P, Q)
    return memo[n]

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().strip().split()
    N = int(data[0])
    P = int(data[1])
    Q = int(data[2])
    print(A(N, P, Q))
