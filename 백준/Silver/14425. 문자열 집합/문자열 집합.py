import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    M = int(data[1])
    
    S = set(data[2:2+N])
    count = 0
    
    for i in range(2+N, 2+N+M):
        if data[i] in S:
            count += 1
    
    print(count)

if __name__ == "__main__":
    main()