import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {-1};
        
        ArrayList<Integer> list = new ArrayList<>();
        for (int e : arr) {
           if (e % divisor == 0) {
               list.add(e);
           }
        }
        
        if (list.size() > 0)
            answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        Arrays.sort(answer);
            
        return answer;
    }
}