// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Ticket {

    public static void main(String[] args) {
        System.out.println(solution(new int[]{1,2,4,5,7,29,30}));
    }


    public static int solution(int[] A) {
        // write your code in Java SE 8

        int l = A.length;
        if(l==0)
            return 0;

        System.out.println(Arrays.toString(A));

        int min=25;

            int c1 = 2 + solution(Arrays.copyOfRange(A,1,l));
            int c2 = 7;
            int j=0;
            while(j<l && A[j] <= A[0]+6)
                j++;
            c2 += solution(Arrays.copyOfRange(A,j,l));
            min=Math.min(Math.min(c1,c2),min);
        System.out.println(min);
        return min;
    }
}