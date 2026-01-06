import java.util.*;
import java.io.*;
import java.awt.Point;

class Solution {
    int N;                  // 조건 수, 최대 100개
    int M = 8;              // 프렌즈 명수
    String[] conditions;    // [알파벳][알파벳][비교문자] 숫자
    int answer = 0;
    
    public int solution(int n, String[] data) {
        N = data.length;
        conditions = new String[N];
        for (int i = 0; i < N; i++) conditions[i] = data[i];
        
        visited = new boolean[M];
        combination = new char[M];
        combi(0);
        
        return answer;
    }
    
    // 조합 제작
    char[] freinds = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    boolean[] visited;
    char[] combination;
    
    public void combi(int cnt) {
        if (cnt == M) {
            if (isValid()) {
                answer++;
            }
            return;
        }
        
        for (int i = 0; i < M; i++) {
            if (!visited[i]) {
                combination[cnt] = freinds[i];
                visited[i] = true;
                combi(cnt+1);
                visited[i] = false;
            }
        }
    }
    
    public boolean isValid() {
        // 알파벳 2개 사이에 조건을 저장
        for (String s : conditions) {
            char x      = s.charAt(0);
            char y      = s.charAt(2);
            char comp   = s.charAt(3);
            int num     = s.charAt(4) - '0'+1;
            
            int xIndex = 0, yIndex = 0;
            for (int i = 0; i < M; i++) {
                if (combination[i] == x) xIndex = i;
                if (combination[i] == y) yIndex = i;
            }
            
            if (comp == '=') {
                if (Math.abs(xIndex-yIndex) != num)  return false;
            } else if (comp == '<') {
                if (Math.abs(xIndex-yIndex) >= num)  return false;
            } else if (comp == '>') {
                if (Math.abs(xIndex-yIndex) <= num)  return false;
            }
        }
        
        return true;
    }
}
