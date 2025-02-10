# 입력을 받습니다.
n = int(input())
tree = {}

for _ in range(n):
    node, left, right = input().split()
    tree[node] = (left, right)

# 전위 순회 (Preorder)
def preorder(node):
    if node == '.':
        return
    print(node, end='')
    preorder(tree[node][0])
    preorder(tree[node][1])

# 중위 순회 (Inorder)
def inorder(node):
    if node == '.':
        return
    inorder(tree[node][0])
    print(node, end='')
    inorder(tree[node][1])

# 후위 순회 (Postorder)
def postorder(node):
    if node == '.':
        return
    postorder(tree[node][0])
    postorder(tree[node][1])
    print(node, end='')

# 순회 결과 출력
preorder('A')
print()
inorder('A')
print()
postorder('A')
print()
