#include <iostream>
using namespace std;

int d[1001];
int arr[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i]) {
				if (d[j] + 1 > d[i]) {
                    d[i] = d[j] + 1;
                }
			}
		}

		if (max < d[i]) {
			max = d[i];
		}
	}

	cout << max << '\n';
	return 0;
}