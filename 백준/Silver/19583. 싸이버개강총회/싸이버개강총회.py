import sys

input = sys.stdin.readline

# 시간 입력 받기
S, E, Q = input().strip().split()

# 출석 체크를 위한 변수 초기화
attendance = {}
result = 0

# 입력 루프
while True:
    line = input().strip()
    if not line:
        break

    # 채팅 기록 처리
    user_time, user_id = line.split()

    # 입장 시간 처리
    if user_time <= S:
        attendance[user_id] = True

    # 퇴장 시간 처리
    elif E <= user_time <= Q and attendance.get(user_id, False):
        attendance[user_id] = False  # 중복 방지
        result += 1

# 결과 출력
print(result)
