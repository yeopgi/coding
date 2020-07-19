import java.util.*;

public class Main {
    static int[][] st = new int[2][100001];
    static int[][] d = new int[2][100001];

    public static void main(String[] args)
    {
        int n, t;
        Scanner scan = new Scanner(System.in);
        t = scan.nextInt();

        for (int i = 1; i <= t; i++) {
            n = scan.nextInt();
        }

        for (int i = 0; i < n; i++) {
            st[0][i] = scan.nextInt();
        }
        
        for (int i = 0; i < n; i++) {
            st[1][i] = scan.nextInt();
        }

        d[0][0] = st[0][0];
        d[1][0] = st[1][0];
        d[0][1] = st[0][1] + d[1][0];
        d[1][1] = st[1][1] + d[0][0];
        for (int i = 2; i < n; i++) {
            d[0][i] = st[0][i] + Math.max(d[1][i - 1], d[1][i - 2]);
            d[1][i] = st[1][i] + Math.max(d[0][i - 1], d[0][i - 2]);
        }

        System.out.println(Math.max(d[0][n - 1], d[1][n - 1]));
    }
}