dasom = list(map(int,list(input())))
num_list = [0 for i in range(10)]
for d in dasom:
    num_list[d] += 1

case1 = num_list[6] + num_list[9]
if case1 %2 ==0:
    num_list[6] = case1//2
    num_list[9] = num_list[6]
else:
    num_list[6] = case1//2+1
    num_list[9] = num_list[6]
print(max(num_list))
