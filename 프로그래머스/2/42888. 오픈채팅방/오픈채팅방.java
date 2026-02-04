import java.util.*;

class Solution {
    public String[] solution(String[] records) {
        String[] answer;
        Line[]   lines  = new Line[records.length];
        HashMap<String, String> map = new HashMap<>();
        
        int i = 0;
        int changeCnt = 0;
        for (String record : records) {
            String[] line = record.split(" ");
            if ("Enter".equals(line[0])) {
                map.put(line[1], line[2]);
                lines[i++] = new Line(line[0], line[1], line[2]);
            } else if("Change".equals(line[0])) {
                map.put(line[1], line[2]);
                lines[i++] = new Line(line[0], line[1], line[2]);
                changeCnt++;
            } else {
                lines[i++] = new Line(line[0], line[1]);
            }
        }
        
        answer = new String[records.length - changeCnt];
        
        i = 0;
        for (Line line : lines) {
            if ("Enter".equals(line.command)) {
                answer[i++] = map.get(line.ID) + "님이 들어왔습니다.";
            } else if("Leave".equals(line.command)) {
                answer[i++] = map.get(line.ID) + "님이 나갔습니다.";
            }
        }
            
        return answer;
    }
    
    class Line {
        String command;
        String ID;
        String nickname;
        
        Line(String x, String y, String z) {
            command = x;
            ID = y;
            nickname = z;
        }
        
        Line(String x, String y) {
            command = x;
            ID = y;
        }
    }
    
}