#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int num[len];
    int i, j, left, right, lidx, ridx, change = 0;

    for (i = 0; i < len; i++) {
        char target = name[i];
        num[i] = min(target - 'A', 'Z' - target + 1);   // name[i]가 a와 z중 어디에서 더 가까운지
        if (num[i] != 0) change++;  // 목표가 같은 문자 아닐 경우
        answer += num[i];
    }

    i = 0;
    int pos = 0;

    if (num[i] != 0) {
        num[i] = 0;
        change--;
    }

    while(change > 0) {

        // 오른쪽 계산
        for (i = pos+1; i < len; i++) {
            if (num[i] != 0) {
                break;
            }
        }

        right = i - pos;
        ridx = i;

        // 왼쪽 계산
        for (i = pos-1; i >= 0; i--) {
            if (num[i] != 0) break;
        }
        if (i < 0) {
            // 왼쪽을 모두 바꿔서 오른쪽 끝으로 돌아가야 하는 경우
            for (j = len-1; j > pos; j--) if (num[j] != 0) break;
            left = pos + (len - j);
            lidx = j;
        } else {
            // 왼쪽에 바꿔야 할 알파벳이 있는 경우
            left = pos - i;
            lidx = i;
        }

        // 이동
        if (left > right) {
            // go right
            answer += right;
            num[ridx] = 0;
            pos = ridx;
        }
        else {
            // go left
            answer += left;
            num[lidx] = 0;
            pos = lidx;
        }

        change--;
    }

    return answer;
}