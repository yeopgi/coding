#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 8;
int N, M;
bool visit[MAX + 1];

void Run(int start, int length, string str)
{
    if (length == M) {
        for (auto i : str) {
            cout << i << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = start; i <= N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            string temp = str + to_string(i);
            Run(i + 1, length + 1, temp);
            visit[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    string str;
    Run(1, 0, "");

    return 0;
}