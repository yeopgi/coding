#include <iostream>
#include <queue>
#include <array>
#include <cstring>
using namespace std;

int col, row;
constexpr int MAX = 100 + 1;
int cheese_map[MAX][MAX];
bool is_visited[MAX][MAX];
const array<int, 4> dx = { -1, 1, 0, 0 };
const array<int, 4> dy = { 0, 0, -1, 1 };
int cnt = 0;
int final_cnt = 0;

namespace curr_state {
	const enum { CHEESE = 1, READY_MELTED, AIR };
}

void change_cheese_to_air()
{
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (cheese_map[i][j] == curr_state::READY_MELTED) {
				cheese_map[i][j] = curr_state::AIR;
			}
		}
	}
}

void search_air()
{
	memset(is_visited, 0, sizeof(is_visited));

	queue<pair<int, int>> air_idx;
	air_idx.push({ 1,1 });
	while (!air_idx.empty()) {
		const int current_air_x_idx = air_idx.front().first;
		const int current_air_y_idx = air_idx.front().second;
		air_idx.pop();
		for (int i = 0; i < dx.size(); i++) {
			const int next_x = current_air_x_idx + dx[i];
			const int next_y = current_air_y_idx + dy[i];
			if (next_x < 1 || next_x > row || next_y < 1 || next_y > col) {
				continue;
			}

			if (is_visited[next_x][next_y]) {
				continue;
			}

			if (!cheese_map[next_x][next_y] || cheese_map[next_x][next_y] == curr_state::AIR) {
				air_idx.push({ next_x, next_y });
				cheese_map[next_x][next_y] = curr_state::AIR;
				is_visited[next_x][next_y] = true;
			}
		}
	}
}

void search_melted_cheese()
{
	memset(is_visited, 0, sizeof(is_visited));

	queue<pair<int, int>> to_be_melted_cheese;
	to_be_melted_cheese.push({ 1,1 });
	while (!to_be_melted_cheese.empty()) {
		const int current_air_x_idx = to_be_melted_cheese.front().first;
		const int current_air_y_idx = to_be_melted_cheese.front().second;
		to_be_melted_cheese.pop();
		for (int i = 0; i < dx.size(); i++) {
			const int next_x = current_air_x_idx + dx[i];
			const int next_y = current_air_y_idx + dy[i];
			if (next_x < 1 || next_x > row || next_y < 1 || next_y > col) {
				continue;
			}

			if (is_visited[next_x][next_y]) {
				continue;
			}

			if (curr_state::AIR == cheese_map[next_x][next_y]) {
				to_be_melted_cheese.push({ next_x, next_y });
				is_visited[next_x][next_y] = true;
			}

			if (cheese_map[current_air_x_idx][current_air_y_idx] == curr_state::AIR &&
				cheese_map[next_x][next_y] == curr_state::CHEESE) {
				cheese_map[next_x][next_y] = curr_state::READY_MELTED;
				to_be_melted_cheese.push({ next_x, next_y });
				is_visited[next_x][next_y] = true;
			}
		}
	}
}

bool is_clear_all()
{
	int remain_cnt = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (curr_state::CHEESE == cheese_map[i][j]) {
				remain_cnt++;
			}
		}
	}

	if (remain_cnt) {
		final_cnt = remain_cnt;
		return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> cheese_map[i][j];
		}
	}

	int cnt = 0;
	while (!is_clear_all()) {
		cnt++;
		search_air();
		search_melted_cheese();
		change_cheese_to_air();
	}

	cout << cnt << '\n';
	cout << final_cnt << '\n';

	return 0;
}