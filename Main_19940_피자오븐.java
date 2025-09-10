import java.io.*;

public class Main_19940_피자오븐 {
    static int T;
    static int target, cur;
    static int dt[] = {60, 10, -10, 1, -1};    // ADDH, MINT, MINT, ADDO, ADDO

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();

        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            target = Integer.parseInt(br.readLine());
            int[] count = new int[5];
            cur = 0;
            count[0] = target/60;
            target %= 60;

            while (target != cur) {
                int minValue = Integer.MAX_VALUE, idx = 0;
                int nextCur = cur;

                for(int i = 0 ; i < 5 ; i++){
                    int next = cur + dt[i];

                    if(Math.abs(next - target) > minValue)
                        continue;
                    
                    minValue = Math.abs(next - target);
                    nextCur = next;
                    idx = i;
                }
                count[idx]++;
                cur = nextCur;
            }

            for(int i = 0 ; i < 5 ; i++)
                answer.append(count[i]).append(" ");
            answer.append("\n");
        }

        System.out.print(answer);
        br.close();
    }
}