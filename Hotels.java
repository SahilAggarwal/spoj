import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

public class Hotels {


    public static void main(String[] args) throws IOException {
        BufferedInputStream bis = new BufferedInputStream(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(bis, StandardCharsets.UTF_8));

        String line = br.readLine();

        while(line != null) {
            String[] tok  = line.split("\\s");
            int n = Integer.parseInt(tok[0]);
            int m = Integer.parseInt(tok[1]);

            String str = br.readLine();
            tok = str.split("\\s");

            ArrayList<Integer> a = new ArrayList<>();
            for(int i=0;i<n;i++) {
                a.add(Integer.parseInt(tok[i]));
            }

            System.out.println(getMax(a, m));
            line = br.readLine();
        }
    }

    private static Long getMax(ArrayList<Integer> a, int m) {
        Long sum=0l;
        Long max=0l;
        int s=0;
        for(int i=0;i<a.size();i++) {
            sum += a.get(i);

            if(sum>m) {
                while (sum > m && s<i) {
                    sum -= a.get(s);
                    s++;
                }
                if(sum > max && sum<=m) {
                    max = sum;
                }
            } else if(sum > max) {
                max = sum;
            }

            if(max==m)
                break;
        }
        return max;
    }
}
