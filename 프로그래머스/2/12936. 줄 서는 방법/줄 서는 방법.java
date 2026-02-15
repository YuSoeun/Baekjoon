import java.util.*;

// 효율성 테스트 시간초과로 정답 참고한 문제

class Solution {
    public int[] solution(int n, long k) {

        // 최종 결과를 담을 배열
        int[] answer = new int[n];

        // 1. 1 ~ n까지 숫자를 담아둘 리스트 생성
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            numbers.add(i);
        }

        // 2. 팩토리얼 값을 미리 계산  fact[i] = i!
        long[] fact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        // 3. k는 1-indexed이므로 0-indexed로 바꿔줌
        long kk = k - 1;

        // 4. 각 자리를 하나씩 채워 나감
        for (int position = 0; position < n; position++) {
            // 남은 자리에서 만들 수 있는 경우의 수 = (남은 개수 - 1)!
            long blockSize = fact[n-1 - position];

            // 즉, 현재 자리에서 선택할 숫자의 인덱스
            int index = (int)(kk / blockSize);

            answer[position] = numbers.get(index);
            numbers.remove(index);

            // 다음 자리 계산을 위해 k값을 갱신
            kk = kk % blockSize;
        }

        return answer;
    }
}