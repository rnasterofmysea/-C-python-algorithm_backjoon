import sys
from collections import OrderedDict

input = sys.stdin.readline
K, L = map(int, input().split())
students = OrderedDict()

for _ in range(L):
    student = input().strip()
    # 만약 이미 등록되어 있다면 기존 항목 삭제 (이전에 등록했던 순서를 없애고)
    if student in students:
        del students[student]
    # 그리고 마지막 신청을 기록 (맨 뒤로 추가됨)
    students[student] = True

# OrderedDict의 key는 학생의 마지막 신청 순서를 반영함.
cnt = 0
for student in students:
    print(student)
    cnt += 1
    if cnt == K:
        break
