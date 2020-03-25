#include <iostream>
using namespace std;

int map[9][9];
int checkList[5] = {1, 2, 3, 4, 5};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int row, col;
    cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k < 5; k++) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (map[i][j] == checkList[k]) {
                    int direct = 4;
                    while (direct--) {
                        int iTemp = i, jTemp = j;
                        while (iTemp <= row) {
                            if (map[iTemp][jTemp] == 0) {
                                map[iTemp][jTemp] = '#';
                                continue;
                            } else if (map[iTemp][jTemp] == 6) {

                            }
                        } 
                    }
                }
            }
        }
    }
        return 0;
}