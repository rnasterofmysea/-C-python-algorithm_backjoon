def bool_def(alphabets):
    for alphabet in alphabets:
        if alphabet != 0:
            return "Impossible"
    return "Possible"

num_case = int(input())
case_bool = []
for i in range(num_case):
    a, b = input().split()
    alphabets = [0 for j in range(26)]
    for x in list(a):
        alphabets[ord(x) - 97] += 1
    for x in list(b):
        alphabets[ord(x) - 97] -= 1
    case_bool.append(bool_def(alphabets))


for case in case_bool:
    print(case)

