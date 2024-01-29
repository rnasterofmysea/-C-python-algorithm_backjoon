import sys

number = int(sys.stdin.readline().strip())
result = 0

for n in range(number):
    key = sys.stdin.readline().strip()
    for i in range(len(key)-1):
        if key[i] in key[i+1:] and key[i] != key[i+1]:
            result += 1
            break


print(number - result)

        
