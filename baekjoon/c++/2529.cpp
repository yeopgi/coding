#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int K;
constexpr int MAX = 9;
constexpr int NUM_LENGTH_MAX = 10;
array<char, MAX + 1> inequality{ 0 };
array<int, NUM_LENGTH_MAX + 1> is_visited{ 0 };
vector<string> ans;

bool is_correct(string& temp)
{
	bool ret = true;
	for (int i = 0; i < K; i++) {
		if (inequality[i] == '<') {
			if (temp[i] >= temp[i + 1]) {
				return ret = false;
			}
		}
		else if (inequality[i] == '>') {
			if (temp[i] <= temp[i + 1]) {
				return ret = false;
			}
		}
	}

	return ret;
}

void Run(const int start_idx, const int depth, string temp)
{
	if (is_visited[start_idx]) {
		return;
	}

	is_visited[start_idx] = true;
	temp += to_string(start_idx);
	if (K == depth) {
		if (is_correct(temp)) {
			ans.push_back(temp);
		}

		is_visited[start_idx] = false;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		Run(i, depth + 1, temp);
	}

	is_visited[start_idx] = false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> inequality[i];
	}

	for (int i = 0; i <= 9; i++) {
		Run(i, 0, "");
		memset(&is_visited, 0x00, sizeof(is_visited));
	}

	sort(ans.begin(), ans.end());

	cout << ans[ans.size() - 1] << '\n';
	cout << ans[0] << '\n';
	return 0;
}
