#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int N;	// 탑의 수
unsigned int _top[500001];
unsigned int receive[500001];
stack<pair<int, int>> s;	// idx, value

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> _top[i];
	}

	for (int i = 1; i <= N; i++) {
		while (!s.empty() && s.top().second < _top[i]) {
			s.pop();
		}

		if (s.empty()) {
			receive[i] = 0;
		} else {
			receive[i] = s.top().first;
		}

		s.push({ i, _top[i] });
	}

	for (int i = 1; i <= N; i++) {
		cout << receive[i] << '\n';
	}

	return 0;
}