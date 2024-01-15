num_list = []
for i in range(7):
    num_list.append(int(input()))

odd_list = [x for x in num_list if x % 2 == 1]

if not odd_list:
    print(-1)
else:
    print(sum(odd_list))
    print(min(odd_list))

