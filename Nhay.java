import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Nhay implements Comparable {
    public static void main(String args[]) throws IOException {
        BufferedInputStream bis = new BufferedInputStream(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(bis, StandardCharsets.UTF_8));

        String line = br.readLine();
        while(line != null) {
            String needle = br.readLine();

            ArrayList<Integer> b = getResetTable(needle);
            int i=0;int j=0;
            char c;
            while(true) {
                c = (char) br.read();
                if(!String.valueOf(c).matches("."))
                    break;

                while(j>=0 && needle.charAt(j) != c) j=b.get(j);
                i++; j++;
                if(j == needle.length()) {
                    System.out.println(i-j);
                    j = b.get(j);
                }
            }

            line=br.readLine();
            if(line != null)
                System.out.println();
        }
    }
    private static ArrayList<Integer> getResetTable(String needle) {
        ArrayList<Integer> b = new ArrayList<>();

        int i=0;int j=-1;
        b.add(j);
        while(i<needle.length()) {
            while(j>=0 && needle.charAt(j) != needle.charAt(i)) j = b.get(j);
            i++; j++;
            b.add(j);
        }
        return b;
    }

    @Override
    public int compareTo(Object o) {
        return 0;
    }
}
