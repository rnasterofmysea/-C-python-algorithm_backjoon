import sys

input = sys.stdin.readline
N, M = map(int, input().split())

addr_dic = {}
for _ in range(N):
    addr, pwd = input().split()
    addr_dic[addr] = pwd
for _ in range(M):
    prompt = input().strip()
    print(addr_dic[prompt])