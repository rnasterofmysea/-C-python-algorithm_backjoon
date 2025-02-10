import sys

input = sys.stdin.readline
N = int(input())

tree = {}

for _ in range(N):
    data, left, right = input().strip().split()
    tree[data] = (left, right)

def preorder(current):
    if current == ".":
        return
    print(current, end='')
    preorder(tree[current][0])
    preorder(tree[current][1])

def inorder(current):
    if current == ".":
        return
    inorder(tree[current][0])
    print(current, end='')
    inorder(tree[current][1])
    
def postorder(current):
    if current == ".":
        return
    postorder(tree[current][0])
    postorder(tree[current][1])
    print(current, end='')
    
preorder("A")
print()
inorder("A")
print()
postorder("A")
