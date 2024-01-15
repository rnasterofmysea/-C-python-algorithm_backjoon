num_list = []
for i in range(9):
    num_list.append(int(input()))
value = max(num_list)
print(value)
print(num_list.index(value)+1)
