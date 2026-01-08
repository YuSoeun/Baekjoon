import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = Long.toString(n);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            list.add(s.charAt(i) - '0');
        }
        
        Collections.sort(list, Collections.reverseOrder());
        
        String rs = new String();
        for (int i = 0; i < s.length(); i++) {
            rs += list.get(i);
        }
        answer = Long.parseLong(rs);
        
        return answer;
    }
}