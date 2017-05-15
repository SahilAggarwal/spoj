import java.util.Scanner;

public class HorribleST {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int t = Integer.parseInt(s.nextLine());
        for (int i = 0; i < t; i++) {
            String st = s.nextLine();
            String[] to = st.split("\\s");
            int n = Integer.parseInt(to[0]);
            int c = Integer.parseInt(to[1]);


            long[] a1 = new long[4*1000000+1];
            long[] a2 = new long[4*1000000+1];

            for (int j = 0; j < c; j++) {
                String str = s.nextLine();
                String[] tok = str.split("\\s");
                int v1 = Integer.parseInt(tok[0]);
                int v2 = Integer.parseInt(tok[1]);
                int v3 = Integer.parseInt(tok[2]);

                Long v4 = 0l;

                if (v1 == 0)
                    v4 = Long.parseLong(tok[3]);


                if(v1==0) {
                    update(a1, a2, v2-1, v3-1, v4, 0, n-1, 0);
                } else {
                    System.out.println(get(a1, a2, v2-1,v3-1, 0,n-1, 0));
                }
            }
        }
    }

    private static long get(long[] a1, long[] a2, int v2, int v3,int s, int e, int i) {
        a1[i] += (e-s+1)*a2[i];
        a2[2*i+1] += a2[i];
        a2[2*i+2] += a2[i];
        a2[i] = 0;

        if(v2 <= s && v3 >= e) {
            return a1[i];
        }

        if(e < v2 || s > v3)
            return 0;

        return (get(a1, a2, v2, v3, s, (s+e)/2, 2*i +1 ) + get(a1, a2, v2, v3, (s+e)/2+1, e, 2*i+2));
    }

    private static void update(long[] a1, long[] a2, int v2, int v3, Long v4, int s, int e, int i) {
        if(v2<=s && v3 >=e) {
            a2[i] += v4;
            a1[i] += (e-s+1)* a2[i];
            a2[2*i+1] += a2[i];
            a2[2*i+2] += a2[i];
            a2[i] = 0;
            return;
        }

        a1[i] += (e-s+1)*a2[i];
        a2[2*i+1] += a2[i];
        a2[2*i+2] += a2[i];
        a2[i] = 0;


        if(e < v2 || s > v3)
            return;

        update(a1, a2, v2, v3, v4, s, (s+e)/2, 2*i+1);
        update(a1, a2, v2, v3, v4, (s+e)/2+1, e, 2*i+2);
        a1[i] = a1[2*i+1] + a1[2*i+2];
    }
}
