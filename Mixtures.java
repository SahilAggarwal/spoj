import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;


class Ret {
    Long smoke;
    int col;

    public Ret(Long smoke, int col) {
        this.smoke = smoke;
        this.col = col;
    }
}

public class Mixtures {

    static Ret[][] mem;

    public static void main(String args[]) throws IOException {
        BufferedInputStream bis = new BufferedInputStream(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(bis, StandardCharsets.UTF_8));

        String line = br.readLine();
        while(line != null) {
            int n = Integer.parseInt(line);
            mem = new Ret[n][n];

            String str = br.readLine();
            String[] tok = str.split("\\s");

            ArrayList<Integer> m = new ArrayList<>();
            m.add();
            for(int i=0;i<n;i++) {
                m.add(Integer.parseInt(tok[i]));
            }
            System.out.println(mix(m, 0, n-1).smoke);
            line = br.readLine();
        }
    }

    private static Ret mix(ArrayList<Integer> m, int i, int j) {

        if(i==j)
            return new Ret(0l, m.get(i));

        if(mem[i][j] != null)
            return mem[i][j];

        Ret min = new Ret(Long.MAX_VALUE, 0);

        for(int k=i;k<j;k++) {
            Ret s1 = mix(m,i,k);
            Ret s2 = mix(m,k+1,j);
            Long count = s1.smoke + s2.smoke + (s1.col*s2.col);
            if(count < min.smoke)
                min=new Ret(count, (s1.col+s2.col)%100);
        }

        mem[i][j] = min;
        return min;

    }
}
