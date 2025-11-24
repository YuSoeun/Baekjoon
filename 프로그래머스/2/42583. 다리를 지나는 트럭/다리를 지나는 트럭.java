import java.util.*;
import java.io.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q = new ArrayDeque<>();
        
        int nowWeight = 0;        // 현재 트럭 총 무게
        for (int i = 0; i < truck_weights.length; i++) {
            // 만약 다리 트럭 수 == bridge_length 빼기
            if (q.size() == bridge_length) {
                nowWeight -= q.poll();
            }
                
            // 만약 트럭 총 무게 > 버티는 무게 -> 0 넣기
            if (nowWeight + truck_weights[i] > weight) {
                q.offer(0);
                i--;
            } else {
                // 아니면 다리에 트럭 넣기
                nowWeight += truck_weights[i];
                q.offer(truck_weights[i]);
            }
            answer++;
        }
        
        return answer + bridge_length;
    }
}