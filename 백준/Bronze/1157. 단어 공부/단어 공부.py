import sys

key = list(sys.stdin.readline().strip())


alphabet = [0 for x in range(26)]
for k in key:
    k = k.upper()
    alphabet[ord(k)-65] += 1

max_alphabet = max(alphabet)

if alphabet.count(max_alphabet) != 1:
    print("?")
else:
    print(chr(alphabet.index(max_alphabet)+65))
