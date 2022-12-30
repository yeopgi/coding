#include <iostream>
#include <vector>
using namespace std;

int T_inform[3];
vector<vector<int>> v;
vector<vector<int>> v2;
vector<vector<int>> inform;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;
    v.resize(N), inform.resize(T);
    v2.resize(N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            inform[i].push_back(temp);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); i++) {
            T_inform[i] = v[i][j];
        }

        int j;
        for (j = 1; j * T_inform[0] <= N; j++) {
        }


        for (j = 1; j * T_inform[0] <= N; j++) {
            for (int k = 0; k < v[j * T_inform[0]].size(); k++) {
                v[j * T_inform[0]][k];
            }
        }
    }




    return 0;
}