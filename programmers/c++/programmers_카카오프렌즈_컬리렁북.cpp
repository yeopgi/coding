// 각각의 원소에 대한 벡터를 생성
// 벡터안에 우선순위 큐 생성해서 각각의 원소에 대한 여러가지의 구획을 집어넣음
// 우선순위 큐라서 가장 앞의 벡터 요소는 해당 원소 구역에 대한 가장 큰 넓이
// 여러 벡터의 맨 앞의 요소값들을 서로 비교
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int Exlpore(vector<vector<int>>& picture, pair<int, int> startPoint, int xLimit, int yLimit, bool visit[100][100])
{
    visit[startPoint.first][startPoint.second] = true;
    queue<pair<int, int>> q;
    int width = 1;
    int atomValue = picture[startPoint.first][startPoint.second];
    q.push(startPoint);
    
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int xTemp = dx[i] + q.front().first;
            int yTemp = dy[i] + q.front().second; 
            if (xTemp >= 0 && xTemp < xLimit && yTemp >= 0 && yTemp < yLimit && !visit[xTemp][yTemp]) {
                if (picture[xTemp][yTemp] != atomValue) {
                    continue;
                }

                q.push({xTemp, yTemp});
                
                visit[xTemp][yTemp] = true;
                width++;
            }
        }

        q.pop();
    }

    return width;
}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {       // m -> 행 ,n  -> 열
    bool visit[100][100];
    memset(visit, false, sizeof(visit));

    int totalArea = 0;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visit[i][j]) {
                int temp = Exlpore(picture, {i, j}, m, n, visit);
                answer[1] = max(answer[1], temp);
                totalArea++;
            }
        }
    }

    answer[0] = totalArea;
    return answer;
}