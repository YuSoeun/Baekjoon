import java.util.*;
class Solution {
    // 자료구조가 보이니 알고리즘을 추측해버렸다.. 스택이라고 처음에 생각 못 했다.
    // java는 top이 아니라 peek!!!!!!!!!!!
    class Point
    {
        int index;
        int price;
        int time;
        
        Point(int x, int y, int z) {
            index = x;
            price = y;
            time = z;
        }
    }
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Point> s = new Stack();
        
        int index = 0;
        int time = 0;
        for (int price : prices) {
            time++;
            while (!s.isEmpty() && s.peek().price > price) {
                Point p = s.pop();
                answer[p.index] = time - p.time;
            }
            s.push(new Point(index++, price, time));
        }
        
        while (!s.isEmpty()) {
            Point p = s.pop();
            answer[p.index] = time - p.time;
        }
        
        return answer;
    }
}