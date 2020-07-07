import java.util.*;

public class Main {
    static int[][] d = new int[10001][10];
    static final int mod = 10007;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        for (int i = 0; i < 10; i++) {
            d[1][i] = 1;
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k <= j; k++) {
                    d[i][j] = d[i][j] + d[i - 1][k];
                    d[i][j] %= mod;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += d[N][i];
        }
        scan.close();
        System.out.println(ans % mod);
    }
}