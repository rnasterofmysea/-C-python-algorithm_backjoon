import sys

def factorial(value, count):
    if count == 0:
        return value
    else:
        return factorial(value * count, count - 1)

count = int(sys.stdin.readline().strip())
result = factorial(1, count)
print(result)
