import java.util.Scanner;

public class Willitst {
    public static void main(String args []) {
        Scanner sb = new Scanner(System.in);
        Long num = sb.nextLong();

        int t=0;
        while(num!=0) {
            if((num & 0x1)>0)
                t++;
            num=num>>1;
        }

        if(t==1)
            System.out.println("TAK");
        else
            System.out.println("NIE");
    }
}
