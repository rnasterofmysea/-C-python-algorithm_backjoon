import sys
from collections import deque
operand_num = int(sys.stdin.readline().strip())

queue = deque([])
for i in range(operand_num):
    o = sys.stdin.readline().rstrip()
    if o == "pop":
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    elif o == "size":
        print(len(queue))
    elif o == "empty":
        if queue:
            print(0)
        else:
            print(1)
    elif o =="front":
        if queue:
            print(queue[0])
        else:
            print(-1)

    elif o == "back":
        if queue:
            print(queue[-1])
        else:
            print(-1)
    else:
        queue.append(int(o[5:]))
