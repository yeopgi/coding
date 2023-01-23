#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	const int MAX_CNT = 1000000;
	array<int, MAX_CNT> my_arr;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		my_arr[i] = num;
	}

	sort(my_arr.begin(), my_arr.begin() + N);

	for (int i = 0; i < N; i++) {
		cout << my_arr[i] << '\n';
	}

	return 0;
}