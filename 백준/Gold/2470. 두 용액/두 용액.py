import sys

input = sys.stdin.readline

N = int(input().strip())  # 정수 N 입력

arry = list(map(int, input().strip().split()))  # 리스트로 변환
arry.sort()  # 정렬

len_arry = len(arry)
count_al = sum(1 for x in arry if x < 0)  # 음수 개수
count_san = len_arry - count_al  # 양수 개수

# 모든 숫자가 음수인 경우 → 절댓값이 작은 두 개 출력
if count_al == len_arry:
    print(arry[-2], arry[-1])
# 모든 숫자가 양수인 경우 → 가장 작은 두 개 출력
elif count_san == len_arry:
    print(arry[0], arry[1])
else:
    # 투 포인터 활용하여 0에 가까운 값 찾기
    result = float('inf')
    result_point1 = 0
    result_point2 = 0
    point1 = 0
    point2 = len_arry - 1  # 마지막 원소부터 시작

    while point1 < point2:
        temp_result = abs(arry[point1] + arry[point2])

        if temp_result < result:
            result_point1 = point1
            result_point2 = point2
            result = temp_result

        if arry[point1] + arry[point2] < 0:
            point1 += 1
        else:
            point2 -= 1

    print(arry[result_point1], arry[result_point2])
