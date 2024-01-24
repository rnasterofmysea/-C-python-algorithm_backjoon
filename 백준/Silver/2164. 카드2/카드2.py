import sys
from collections import deque

total = int(sys.stdin.readline().strip())

cards = deque([t for t in range(1,total+1)])

for t in range(total):
    if t == total-1:
        print(cards[0])
        break
    cards.popleft()

    cards.append(cards.popleft())
