import sys

sugar = int(sys.stdin.readline().strip())
min_box = sugar
for i in range(sugar):
    for j in range(sugar):
        result = 5 * i + 3 * j
        if result == sugar and (i + j) < min_box:
            min_box = i + j

if min_box == sugar:
    print(-1)
else:
    print(min_box)

