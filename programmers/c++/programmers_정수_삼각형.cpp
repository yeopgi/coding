#include <algorithm>
#include <vector>

using namespace std;

int d[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = d[0][0] = triangle[0][0];
    int height = triangle.size();

    for (int i = 1; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                d[i][j] = d[i - 1][j - 1] + triangle[i][j];
            } else {
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
            }

int solution(vector<vector<int>> triangle) {
    int answer = d[0][0] = triangle[0][0];
    int height = triangle.size();

    for (int i = 1; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][j] + triangle[i][j];
            } else if (j == i) {

            answer = max(answer, d[i][j]);
        }
    }

    return answer;
}