alphabet =[0 for i in range(26)]
a = list(map(ord,list(input())))

for v in a :
        alphabet[v - 97]+=1

for i in alphabet:
    print(i, end = ' ')
