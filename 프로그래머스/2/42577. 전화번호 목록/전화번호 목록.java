import java.util.*;
import java.lang.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashSet <String> phones = new HashSet<>();
        
        for (String phone : phone_book) {
            phones.add(phone);
        }
        
        for (String phone : phone_book) {
            String cur = new String();
            for (int i = 0; i < phone.length()-1; i++) {
                if (phones.contains(phone.substring(0, i+1))) {
                    //System.out.println("sub string: " + phone.substring(0, i+2));
                    return false;
                }
            }
        }
        
        return answer;
    }
}