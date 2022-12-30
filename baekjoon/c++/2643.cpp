#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
vector<pair<int, int>> paperList;
int paper;
int cache[MAX + 1];
int secondValueList[MAX + 1];

bool _Compare(const pair<int, int> &src1, const pair<int, int> &src2)
{
    if (src1.first == src2.first) {
        return src1.second < src2.second;
    }

    return src1.first < src2.first;
}

int _lower_bound(int start, int end, const int target)
{
    int mid;
    while (end - start > 0) { // 주어진 범위[start,end]에서 탐색하도록 한다. start == end이면 반복 종료
        mid = (start + end) / 2; // 주어진 범위의 중간 위치를 계산한다
        if (cache[mid] <= target) // 찾고자 하는 값보다 작으면 오른쪽으로 한 칸만 더 시작 구간 갱신
            start = mid + 1;

        else // 찾고자 하는 값보다 크면 거기까지 끝 구간 갱신
            end = mid;
    }
    return end + 1; // 찾는 구간에 없는 경우 가장 마지막 +1 위치 전달
}

int Run()
{
    int j = 1;
    cache[1] = secondValueList[1];
    for (int i = 2; i <= paper; i++) {
        if (cache[j] <= secondValueList[i]) {
            cache[j + 1] = secondValueList[i];
            j++;
        } else {
            int ans = _lower_bound(1, j, secondValueList[i]);
            cache[ans - 1] = secondValueList[i];
        }
    }

    return j;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> paper;
    paperList.resize(paper + 1);
    for (int i = 1; i <= paper; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 < temp2) {    // 가로 길이가 무조건 세로 길이보다 길도록 설정
            swap(temp1, temp2); // temp1을 가로 길이로 상정
        }

        paperList[i] = {temp1, temp2};
        secondValueList[i] = temp2;
    }

    sort(paperList.begin(), paperList.end(), _Compare);

    int ans = Run();
    cout << ans + 1 << '\n';
    return 0;
}