import sys

test_case = int(sys.stdin.readline().strip())
for t in range(test_case):
    k = int(sys.stdin.readline().strip())
    n = int(sys.stdin.readline().strip())

    a = [i for i in range(1,14+1)]

    for i in range(k):
        b = []
        for j in range(1,n+1):
            b.append(sum(a[:j]))
        a = b

    result = a.pop()
    print(result)
