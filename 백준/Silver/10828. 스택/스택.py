import sys

stack = []
top =-1
num_operands = int(sys.stdin.readline().strip())

for i in range(num_operands):
    operand = sys.stdin.readline().strip() 
    if operand =="pop":
        if top == -1:
            print(-1)
        else:
            top -= 1
            print(stack.pop())
        
    elif operand =="size":
        print(len(stack))

    elif operand == "empty":
        if top == -1:
            print(1)
        else:
            print(0)

    elif operand == "top":
        if top == -1:
            print(-1)
        else:
            print(stack[top])

    else:
        value = int(operand[5:])
        top += 1
        stack.append(value)
        
