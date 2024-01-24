import sys

num_value = int(sys.stdin.readline().strip())

def process(value):
    stack = []
    top = -1
    for v in value:
        if v == "(":
            stack.append("(")
            top += 1
        elif v == ")":
            if top == -1:
                return False
            else:
                stack.pop()
                top -= 1
    if stack:
        return False
    else: return True
for n in range(num_value):
    value = list(sys.stdin.readline().strip())
    if process(value):
        print("YES")
    else:
        print("NO")

         
