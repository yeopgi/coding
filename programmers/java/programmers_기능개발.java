import java.util.ArrayList;
import java.math.*;
import java.util.*;

public class Solution {
	public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        Queue<Integer> q = new LinkedList<Integer>();        
		ArrayList<Integer> list = new ArrayList<>();
		int progressesListCnt = progresses.length;
		for (int j = 0; j < progressesListCnt; j++) {
	        progresses[j] = (int)Math.ceil((double)(100 - progresses[j]) / speeds[j]);
	    }
		
		int offset = 0;
		for (int i = 0; i < progressesListCnt; i += offset) {
            if (i == progressesListCnt - 1) {
                q.add(1);
                break;
            }
            int complete = 0;
            int temp = progresses[i];
            complete++;
            int j;
            for (j = i + 1; j < progressesListCnt; j++) {
                if (temp >= progresses[j]) {
                    complete++;
                } else {
                    offset = complete;                
                    break;
                }
            }
            
            q.add(complete);
            
            if (j == progressesListCnt) {
                break;
            }
        }

        answer = new int[q.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = q.poll();
        }
        
		return answer;
	}
}
