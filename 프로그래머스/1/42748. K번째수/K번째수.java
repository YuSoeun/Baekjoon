import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        
        for (int e : array) {
            arr.add(e);
        }
        
        for (int[] command : commands) {
            int i = command[0];
            int j = command[1];
            int k = command[2];
            
            // 자르기
            List<Integer> cur = new ArrayList(arr);
            cur = cur.subList(i-1, j);
        
            // 정렬
            Collections.sort(cur);

            // k번째 숫자
            answer.add(cur.get(k-1));
        }
        
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}