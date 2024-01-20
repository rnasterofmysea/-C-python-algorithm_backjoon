cal_result = 1
for i in range(3):
    cal_result = cal_result * int(input())

count = [0 for x in range(10)]
value = list(map(int,list(str(cal_result))))
for v in value:
    count[v] += 1

for c in count:
    print(c)

