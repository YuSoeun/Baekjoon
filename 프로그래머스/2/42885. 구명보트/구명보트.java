import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        
        int left = 0;
        int right = people.length - 1;
        int answer = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;   // 가벼운 사람 태움
            }
            right--;      // 무거운 사람은 항상 태움
            answer++;     // 보트 1대 사용
        }
        
        return answer;
    }
}