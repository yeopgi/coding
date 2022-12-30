import java.util.*;

class Pair{
    public int left;
    public int right;

    public Pair(int left, int right)
    {
        this.left = left;
        this.right = right;
    }

    public Pair()
    {

    }
}

class Solution {
    public static int Explore(int[][] picture, Pair pair , int xLimit, int yLimit, boolean[][] visit)
    {
        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };
        visit[pair.left][pair.right] = true;
        Queue<Pair> q = new LinkedList<Pair>();
        int width = 1;
        int atomValue = picture[pair.left][pair.right];
        q.add(pair);

        while (!q.isEmpty()) {
            for (int i = 0; i < 4; i++) {
                int xTemp = dx[i] + q.peek().left;
                int yTemp = dy[i] + q.peek().right;
                if (xTemp >= 0 && xTemp < xLimit && yTemp >= 0 && yTemp < yLimit && !visit[xTemp][yTemp]) {
                    if (picture[xTemp][yTemp] != atomValue) {
                        continue;
                    }
    
                    Pair srcPair = new Pair(xTemp, yTemp);
                    q.add(srcPair);
    
                    visit[xTemp][yTemp] = true;
                    width++;
                }
            }
    
            q.poll();
        }

        return width;
    }

    public int[] solution(int m, int n, int[][] picture) {
        boolean[][] visit = new boolean[100][100];
        for (int i = 0; i < visit.length; i++) {
            for (int j = 0; j < visit.length; j++) {
                visit[i][j] = false;
            }
        }

        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        int totalArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] != 0 && !visit[i][j]) {
                    Pair pair = new Pair(i, j);
                    int temp = Explore(picture, pair, m, n, visit);
                    answer[1] = Math.max(answer[1], temp);
                    totalArea++;
                }
            }
        }

        answer[0] = totalArea;
        return answer;
    }
}