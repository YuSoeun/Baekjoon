import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] nums = s.split(" ");
        int max = -1_000_000_000;
        int min = 1_000_000_000;
        
        for (String num : nums) {
            int cur = Integer.parseInt(num);
            max = Math.max(max, cur);
            min = Math.min(min, cur);
        }
        
        answer += Integer.toString(min) + " ";
        answer += Integer.toString(max);
        
        return answer;
    }
}