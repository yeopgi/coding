#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, L, R;
int A[51][51];
int visit[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int openBorder = 0;
int unitedPeople = 0;
int average = 0;
vector<pair<int, int>> openCountry;

void Explore(pair<int, int> src) 
{
    if (visit[src.first][src.second]) {
        return;
    } 

    visit[src.first][src.second] = true;
    for (int i = 0; i < 4; i++) {
        int xTemp = src.first + dx[i];
        int yTemp = src.second + dy[i];
        int diff = abs(A[src.first][src.second] - A[xTemp][yTemp]);
        if (xTemp >= 1 && xTemp <= N && yTemp >= 1 && yTemp <= N && diff >= L && diff <= R && !visit[xTemp][yTemp]) {
            openCountry.push_back({xTemp, yTemp});
            openBorder++;
            unitedPeople += A[xTemp][yTemp];
            Explore({xTemp, yTemp});
        }
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    int answer = 0;
    while (true) {
        memset(visit, false, sizeof(visit));

        bool isMove = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visit[i][j]) {
                    continue;
                }

                openBorder = 1;
                openCountry.clear();

                openCountry.push_back({i, j});

                unitedPeople += A[i][j];
                Explore({i, j});

                if (openBorder >= 2) {
                    isMove = true;
                    average = unitedPeople / openBorder;
                    for (int i = 0; i <= openCountry.size(); i++) {
                        A[openCountry[i].first][openCountry[i].second] = average;
                    }
                }

            }
        }

        if (isMove) {
            answer++;
        } else {
            break;
        }
    }

    cout << answer << '\n';
    return 0;
}