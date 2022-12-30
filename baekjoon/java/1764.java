import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); // 듣도 못한 사람의 수
        int m = scan.nextInt(); // 보도 못한 사람의 수
        scan.nextLine(); // 개행문자 제거

        List<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(scan.nextLine());
        }
        Collections.sort(list);

        List<String> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String name = scan.nextLine();
            if (Collections.binarySearch(list, name) >= 0) {
                result.add(name);
            }
        }
        Collections.sort(result);

        System.out.println(result.size());
        for (String str : result) {
            System.out.println(str);
        }
    }
}