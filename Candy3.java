import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Candy3 {
    public static void main(String args[]) {
        Scanner sb = new Scanner(System.in);
        Integer t = new Integer(sb.nextLine());

        for(int i=0;i<t;i++) {
            String l = sb.nextLine();
            if(l.length() == 0) {
                i--;
                continue;
            }
            Integer n = new Integer(l);
            BigInteger sum = new BigInteger("0");
            for(int j=0;j<n;j++) {
                sum = sum.add(new BigInteger(sb.nextLine()));
            }
            System.out.println((sum.mod(new BigInteger(n.toString())).compareTo(new BigInteger("0")) == 0) ? "YES" : "NO");
        }
    }

}
