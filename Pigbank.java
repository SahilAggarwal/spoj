import java.util.*;


class Coin {
    public int v;
    public int w;

    public Coin(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

public class Pigbank {
    static Long[][] m;

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for(int i=0;i<t;i++) {
            int w1 = s.nextInt();
            int w2 = s.nextInt();

            int n = s.nextInt();
            List<Coin> c = new ArrayList<>();
            for(int j=0;j<n;j++) {
                int a = s.nextInt();
                int b = s.nextInt();

                c.add(new Coin(a,b));
            }

            m = new Long[10000][500];
            Long min = getMin(c,w2-w1,0);

            if(min!=-1) {
                System.out.printf("The minimum amount of money in the piggy-bank is %d.\n",min);
            } else {
                System.out.println("This is impossible.");
            }
        }
    }

    private static Long getMin(List<Coin> c, int w, int i) {

        if(w==0)
            return 0l;

        if(w<0 || i==c.size())
            return -1l;

        if(m[w][i] != null)
            return m[w][i];

        Long m1 =  getMin(c, w-c.get(i).w,i);
        Long m2 = getMin(c, w, i+1);

        if(m1==-1 && m2 == -1) {
            m[w][i] = -1l;
            return -1l;
        }

        Long min;
        if(m1 == -1)
            min = m2;
        else if(m2 == -1)
            min =  c.get(i).v + m1;
        else
            min = Math.min(c.get(i).v + m1, m2);
        m[w][i] = min;
        return min;
    }
}
