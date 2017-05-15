import java.util.*;

public class Buglife {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for(int i=0;i<t;i++) {
            int n = s.nextInt();
            int m = s.nextInt();
            Map<Integer, ArrayList<Integer>> g = new HashMap<>();
            for(int j=0;j<m;j++) {
                int a = s.nextInt();
                int b = s.nextInt();

                if(g.containsKey(a-1)) {
                    g.get(a - 1).add(b - 1);
                } else {
                    ArrayList<Integer> temp = new ArrayList<>();
                    temp.add(b-1);
                    g.put(a-1, temp);
                }
            }

            System.out.printf("Scenario #%d:\n",i+1);
            if(!isBipartite(g,n)) {
                System.out.println("Suspicious bugs found!");
            } else {
                System.out.println("No suspicious bugs found!");
            }
        }
    }

    private static boolean isBipartite(Map<Integer, ArrayList<Integer>> g, int n) {
        int[] col = new int[n];
        Arrays.fill(col, -1);


        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        col[0]=1;

        while (q.size() !=0) {

            int t = q.poll();

            if(g.containsKey(t)) {
                ArrayList<Integer> nodes = g.get(t);

                for (int i = 0; i < nodes.size(); i++) {
                    if (col[nodes.get(i)] == -1) {
                        col[nodes.get(i)] = 1 - col[t];
                        q.add(nodes.get(i));
                    } else if (col[nodes.get(i)] == col[t]) {
                        return false;
                    }
                }
                g.remove(t);
            }

            if(q.size() == 0 && g.size() > 0) {
                Map.Entry<Integer, ArrayList<Integer>> e = g.entrySet().iterator().next();
                q.add(e.getKey());
            }
        }
        return true;
    }
}
