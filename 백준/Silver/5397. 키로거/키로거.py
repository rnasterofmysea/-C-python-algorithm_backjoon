test_num = int(input())
passwards = []
for t in range(test_num):
    passwards.append(input())    

for t in range(test_num):
    
    left = []
    right = []

    for p in passwards[t]:
        if p == "<":
            if left:
                right.append(left.pop())
                
        elif p == ">":
            if right:
                left.append(right.pop())

        elif p == "-":
            if left:
                left.pop()
        else:
            left.append(p)

    print( "".join(left), "".join(right[::-1]), sep="")
