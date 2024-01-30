import sys

s_num = int(sys.stdin.readline().strip())

s_cards = list(map(int,sys.stdin.readline().rstrip().split()))
s_cards.sort()

n_num = int(sys.stdin.readline().strip())
n_cards = list(map(int, sys.stdin.readline().rstrip().split()))

for n in n_cards:
    target = n
    start = 0
    end = s_num-1
    flag = 0
    while start <= end:
        mid = (start + end)//2
        if s_cards[mid] == target:
            flag = 1
            break
        elif s_cards[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    print(flag, end = ' ')
    
