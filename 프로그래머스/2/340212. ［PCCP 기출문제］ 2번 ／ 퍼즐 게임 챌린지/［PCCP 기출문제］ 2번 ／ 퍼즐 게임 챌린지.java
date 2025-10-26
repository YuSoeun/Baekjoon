import java.util.*;
import java.io.*;

class Solution {
    long N;  // 퍼즐/시간 수
    long LIMIT;
    long MAX = 1_000_000_000_000_000L;
    long answer = 1_000_000_000_000_000L;
    
    public int solution(int[] diffs, int[] times, long limit) {
        N = diffs.length;
        LIMIT = limit;
        long cur = MAX;
        
        binary_search(1, cur, diffs, times);
        
        return (int)answer;
    }
    
    void binary_search(long left, long right, int[] diffs, int[] times) {
        long mid = (left + right)/2;
        
        // System.out.println("left:" + left + " right:" + right + " mid:" + mid);
        if (left < 1 || right > MAX) return;
        if (left > right) return;
        
        if (isValid(mid, diffs, times)) {
            // System.out.println("isValid!!");
            answer = Math.min(mid, answer);
            binary_search(left, mid-1, diffs, times);
        } else {
            // System.out.println("Nope!!");
            binary_search(mid+1, right, diffs, times);
        }
    }
    
    boolean isValid(long level, int[] diffs, int[] times) {
        long sum = 0;
        
        for (int i = 0; i < N; i++) {
            if (diffs[i] <= level) 	sum += times[i];
            else 					sum += (times[i] + times[i-1]) * (diffs[i] - level) + times[i];
            
            // System.out.println(sum + "/" + LIMIT);
            if (sum > LIMIT) return false;
        }

        return true;
    }
}