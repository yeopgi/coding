#include <iostream>
using namespace std;

int N;
long long _distance[100001];
long long price[100001];
int total = 0;

void Run(int _total, int start)
{
    for (int i = 1; i <= N; i++) {
        Run(_total, i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> _distance[i];
        total += _distance[i];
    }

    for (int i = 1; i <= N; i++)
        cin >> price[i];



}