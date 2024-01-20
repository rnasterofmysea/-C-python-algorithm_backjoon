stars = int(input())

for i in range(1, stars*2):
    if i <= stars:
        print( " " * (stars - i)+ "*" *(2*i-1))
    else:
        value = i - stars
        print( " " * value+ "*"* (2*stars - (2*value + 1)))
