#include <iostream>
#include <cstring> //memset
using namespace std;

const int MAX = 1000;
int N; //상자의 개수
int cache[MAX + 1], box[MAX];
//box[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환

int boxLIS(int start) //
{
    int &result = cache[start + 1];
    if (result != -1) {
        return result;
    }

    result = 0;
    for (int next = start + 1; next < N; next++) {
        if (start == -1 || box[start] < box[next]) {
            int candidate = boxLIS(next) + 1;
            if (candidate > result) {
                result = candidate;
            }
        }
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> box[i];
    }

    memset(cache, -1, sizeof(cache));
    cout << boxLIS(-1) << endl;
    return 0;
}
