import sys
while True:
    value = sys.stdin.readline().rstrip()
    if value == ".":
            break
    stack = []
    for v in value:
        if v == "(" or v == "[":
            stack.append(v)
        elif v == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                stack.append(")")
                break
        elif v == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                stack.append("]")
                break
    if stack:
        print("no")
    else:
        print("yes")
