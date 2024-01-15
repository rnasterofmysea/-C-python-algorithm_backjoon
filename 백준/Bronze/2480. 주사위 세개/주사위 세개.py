dice_list = list(map(int, input().split()))
count_list = [0,0,0,0,0,0]

for dice in dice_list:
    count_list[dice-1] += 1


if 3 in count_list:
    print((count_list.index(3)+1)* 1000 + 10000)

elif 2 in count_list:
    print((count_list.index(2)+1) * 100 + 1000)

else: print(max(dice_list) * 100)
