"""
https://www.acmicpc.net/problem/1354
python_BOJ_1354_무한 수열2
"""
import sys
input = sys.stdin.readline
hash = {0 : 1}

def A(n, P, Q, X, Y):

    if n in hash:
        return hash[n]
    
    hash[n] =  A(max(0, n //P - X), P, Q, X, Y) + A(max(0, n // Q - Y), P, Q, X, Y)
    return hash[n]

N, P, Q, X, Y = map(int, input().split())
print(A(N, P, Q, X, Y))


