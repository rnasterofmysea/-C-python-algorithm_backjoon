number = int(input())

def dp(n):
    if n == 1:
        return 0
    memo = [0] * (n + 1)
    for i in range(2, n + 1):
        memo[i] = memo[i - 1] + 1
        if i % 2 == 0:
            memo[i] = min(memo[i], memo[i // 2] + 1)
        if i % 3 == 0:
            memo[i] = min(memo[i], memo[i // 3] + 1)
    return memo[n]

print(dp(number))
