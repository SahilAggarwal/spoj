
import java.util.*;

class Account implements Comparable{
    int cd;
    int b;
    int a1;
    int a2;
    int a3;
    int a4;

    public Account(int cd, int b, int a1, int a2, int a3, int a4) {
        this.cd = cd;
        this.b = b;
        this.a1 = a1;
        this.a2 = a2;
        this.a3 = a3;
        this.a4 = a4;
    }

    public int compareTo(Object o) {
        
        Account ac = (Account) o;
        
        if(cd < ac.cd)
            return -1;
        else if(cd > ac.cd)
            return 1;
        else {
            if(b < ac.b)
                return -1;
            else if(b > ac.b)
                return 1;
            else {
                if(a1 < ac.a1)
                    return -1;
                else if(a1 > ac.a1)
                    return 1;
                else {
                    if(a2 < ac.a2)
                        return -1;
                    else if(a2 > ac.a2)
                        return 1;
                    else {
                        if(a3 < ac.a3)
                            return -1;
                        else if(a3 > ac.a3)
                            return 1;
                        else {
                            if(a4 < ac.a4)
                                return -1;
                            else if(a4 > ac.a4)
                                return 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Account account = (Account) o;

        if (cd != account.cd) return false;
        if (b != account.b) return false;
        if (a1 != account.a1) return false;
        if (a2 != account.a2) return false;
        if (a3 != account.a3) return false;
        return a4 == account.a4;

    }

    public int hashCode() {
        int result = cd;
        result = 31 * result + b;
        result = 31 * result + a1;
        result = 31 * result + a2;
        result = 31 * result + a3;
        result = 31 * result + a4;
        return result;
    }

    public String toString() {
        return String.format("%02d",cd)  + " " + String.format("%08d",b) + " " + String.format("%04d",a1) + " " + String.format("%04d",a2) + " " + String.format("%04d",a3) + " " + String.format("%04d",a4);
    }
}

public class Sbank {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int t = s.nextInt();


        for(int i=0;i<t;i++) {
            int n = s.nextInt();

           List<Account> ac = new ArrayList<Account>();

            for (int j=0;j<n;j++) {

                int a = s.nextInt();
                int b = s.nextInt();
                int c = s.nextInt();
                int d = s.nextInt();
                int e = s.nextInt();
                int f = s.nextInt();

                ac.add(new Account(a,b,c,d,e,f));
            }

            Collections.sort(ac);


            int c=1;
            for(int k=1;k<ac.size();k++) {
                if(ac.get(k).equals(ac.get(k-1)))
                    c++;
                else {
                    System.out.printf("%s %d\n", ac.get(k-1), c);
                    c=1;
                }
            }
            System.out.printf("%s %d\n", ac.get(ac.size()-1), c);

            if(i!=ac.size()-1)
                System.out.println();
        }
    }
}
