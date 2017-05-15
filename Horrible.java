import java.util.Arrays;
import java.util.Scanner;

public class Horrible {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int t = Integer.parseInt(s.nextLine());
        for(int i=0;i<t;i++) {
            String st = s.nextLine();
            String[] to = st.split("\\s");
            int n = Integer.parseInt(to[0]);
            int c = Integer.parseInt(to[1]);

            long[] a1 = new long[100002];
            long[] a2 = new long[100002];

            for(int j=0;j<c;j++) {
                String str = s.nextLine();
                String[] tok = str.split("\\s");
                int v1 = Integer.parseInt(tok[0]);
                int v2 = Integer.parseInt(tok[1]);
                int v3 = Integer.parseInt(tok[2]);

                Long v4=0l;

                if(v1 == 0)
                    v4 = Long.parseLong(tok[3]);

                try {
                    if (v1 == 0) {
                        update(a1, n, v2, v4);
                        update(a1, n, v3+1, -v4);
                        update(a2, n, v2, v4*(v2-1));
                        update(a2, n, v3+1, -v4*v3);
                    } else {
                        Long left = get(a1, v2-1)*(v2-1) - get(a2, v2-1);
                        Long right = get(a1, v3)*v3 - get(a2, v3);
                        System.out.println(right-left);
                    }
                } catch (Exception e) {
                    return;
                }
            }
        }
    }

    private static Long get(long[] a, int i) {
        Long s=0l;
        for(int j=i;j>0;j = j - (j&-j)) {
            s += a[j];
        }
        return s;
    }


    private static void update(long[] a, int n, int i, Long v4) {
            for(int j=i;j<=n;j = j + (j&-j)) {
                a[j] = a[j] + v4;
            }
    }
}
