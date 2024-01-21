total_num, max_room = map(int, input().split())
male_students = [0 for x in range(6)]
female_students = [0 for x in range(6)]
count = 0
for i in range(total_num):
    gender, grade = map(int,input().split())
    if gender == 0:
        female_students[grade-1] += 1
    else : male_students[grade-1] += 1

total = male_students + female_students
for x in total:
    if x % max_room == 0:
        count += x // max_room
    else:
        count = count + x // max_room + 1
        
print(count)
