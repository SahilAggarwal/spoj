import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Fashion {
    public static void main(String args[]) {
        Scanner sb = new Scanner(System.in);
        int t = sb.nextInt();


        for(int i=0;i<t;i++) {
            ArrayList<Integer> m=new ArrayList<>();
            ArrayList<Integer> w=new ArrayList<>();

            int n = sb.nextInt();

            for(int j=0;j<n;j++) {
                m.add(sb.nextInt());
            }

            for(int j=0;j<n;j++) {
                w.add(sb.nextInt());
            }
            System.out.println(getMax(m,w));
        }
    }

    private static int getMax(ArrayList<Integer> m, ArrayList<Integer> w) {
        Collections.sort(m);
        Collections.sort(w);

        int max=0;

        for(int i=0;i<m.size();i++) {
            max += m.get(i)*w.get(i);
        }

        return max;
    }
}
