import sys

def factorial(n):
    if n == 0:
        return 1
    return factorial(n-1) * n

n = int(sys.stdin.readline().strip())
print(factorial(n))