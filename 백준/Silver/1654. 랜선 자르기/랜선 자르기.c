#include <stdio.h>

int main() {
    int K, N;
    int arry[10000];
    long long max = 0;  // 최대 길이를 저장하기 위해 long long 사용
    long long result = 0;

    // 입력 처리
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++) {
        scanf("%d", &arry[i]);
        if(max < arry[i]) {
            max = arry[i];
        }
    }

    // 이진 탐색 범위 설정
    long long start = 1;
    long long end = max;

    // 이진 탐색 수행
    while(start <= end) {
        long long mid = (start + end) / 2;  // mid 값을 long long으로 처리
        long long temp = 0;

        // 현재 mid 길이로 잘랐을 때 만들 수 있는 랜선 개수 계산
        for(int i = 0; i < K; i++) {
            temp += arry[i] / mid;

            // 최적화: 이미 N개 이상이면 더 이상 계산할 필요 없음
            if(temp >= N) {
                break;
            }
        }

        // 목표 개수 N개보다 적게 만들 수 있으면 더 짧게 잘라야 함
        if(temp < N) {
            end = mid - 1;
        } 
        // 목표 개수 N개 이상 만들 수 있으면 더 길게 잘라볼 수 있음
        else {
            result = mid;  // 현재 mid 값 저장
            start = mid + 1;
        }
    }

    // 결과 출력
    printf("%lld", result);
    return 0;
}
