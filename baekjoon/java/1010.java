import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int[][] d = new int[31][31];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int l = 0; l < T; l++) {
            int N = scan.nextInt(); // 듣도 못한 사람의 수
            int M = scan.nextInt(); // 보도 못한 사람의 수
            for (int i = 1; i <= M; i++) {
                d[1][i] = i;
            }

            scan.nextLine();

            for (int i = 2; i <= N; i++) {
                for (int j = i; j <= M; j++) {
                    for (int k = j; k >= i; k--) {
                        d[i][j] = d[i][j] + d[i - 1][k - 1];
                    }
                }
            }

            System.out.println(d[N][M]);
           
	    for (int[] row : d) {
            	Arrays.fill(row, 0);
	    } 
        }
    }
}
