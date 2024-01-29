import sys

croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
word = sys.stdin.readline().rstrip()

for c in croatia :
    word = word.replace(c, '*')
print(len(word))