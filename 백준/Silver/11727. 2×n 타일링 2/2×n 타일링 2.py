
n = int(input())

dp = []

dp.append(1)
dp.append(3)

for i in range(2,n):
    dp.append((dp[i-2] * 2  + dp[i-1]) % 10007)

print(dp[n-1])