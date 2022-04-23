#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int t;
    cin >> t;
	while (t--) {
        int current, next, cnt;
        cin >> cnt;
    	vector<string> v(cnt);
		for (int i = 0; i < cnt; i++) {
            string str;
            cin >> str;
            v[i] = str;
        }

		sort(v.begin(), v.end());

        int i;
		for (i = 0; i < cnt - 1; ++i) {
			current = v[i].length();
			next = v[i + 1].length();
			if (current >= next) {
				continue;
			}

			if (v[i + 1].substr(0, current) == v[i]) {
				printf("NO\n");
				break;
			}
		}

		if (i == cnt - 1) {
			printf("YES\n");
		}
	}

	return 0;
}