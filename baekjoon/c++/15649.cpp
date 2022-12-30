#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[1 + 8];
bool visited[1 + 8];

void Run(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            Run(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> N >> M;

    Run(0);
    return 0;
}