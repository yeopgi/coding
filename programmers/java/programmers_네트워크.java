import java.util.*;

class Solution {
    boolean[] visit = new boolean[200];

    void Dfs(int src, List<List<Integer>> list) {
        if (visit[src]) {
            return;
        }

        visit[src] = true;
        for (int i = 0; i < list.get(src).size(); i++) {
            Dfs(list.get(src).get(i), list);
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        int except = 0;
        List<List<Integer>> list = new ArrayList<List<Integer>>(n);
        for (int i = 0; i < n; i++) {
            list.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                if (computers[i][j] == 1) {
                    list.get(i).add(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                continue;
            }

            if (list.get(i).size() == 0) {
                except++;
                continue;
            }

            Dfs(i, list);
            answer++;
        }

        answer += except;
        return answer;
    }
}