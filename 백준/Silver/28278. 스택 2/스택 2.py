import sys

num_operands = int(sys.stdin.readline().strip())

top = -1
stack = []
for n in range(num_operands):
    operand = sys.stdin.readline().strip()

    if operand == "2":
        if top == -1:
            print(-1)
        else:
            value = stack.pop()
            top -= 1
            print(value)
    elif operand == "3":
        print(top + 1)

    elif operand == "4":
        if top == -1:
            print(1)
        else: print(0)
    elif operand == "5":
        if top == -1:
            print(-1)
        else: print(stack[top])

    else:
        stack.append(int(operand[2:]))
        top += 1
