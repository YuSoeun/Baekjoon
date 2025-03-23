import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N, zeroCount, oneCount;
    static ArrayList<Integer> plus = new ArrayList<>();
    static ArrayList<Integer> minus = new ArrayList<>(); // with zero

    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int temp = Integer.parseInt(st.nextToken());

            if      (temp > 1)  plus.add(temp);
            else if (temp == 0) zeroCount++;
            else if (temp == 1) oneCount++;
            else                minus.add(temp);
        }

        int sum = 0;
        if (plus.size() > 0) {
            Collections.sort(plus, Collections.reverseOrder());
            for (int i = 0; i < plus.size(); i++) {
                if (i+1 < plus.size()) {
                    sum += plus.get(i) * plus.get(i+1);
                    i++;
                } else {
                    sum += plus.get(i);
                }
            }
        }

        if (minus.size() > 0) {
            Collections.sort(minus);
            for (int i = 0; i < minus.size(); i++) {
                if (i + 1 < minus.size()) {
                    sum += minus.get(i) * minus.get(i + 1);
                    i++;
                } else {
                    if (zeroCount == 0) {
                        sum += minus.get(i);
                    }
                }
            }
        }

        System.out.println(sum + oneCount);
    }
}