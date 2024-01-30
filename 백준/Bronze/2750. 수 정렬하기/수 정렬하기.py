import sys

key = int(sys.stdin.readline().strip())

values = [int(sys.stdin.readline().strip()) for x in range(key)]
for v in range(key -1):
    for k in range(v,key):
        if values[v] > values[k]:
            temp = values[k]
            values[k] = values[v]
            values[v] = temp
print(*values, sep = "\n")
            
