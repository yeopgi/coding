#include <iostream>
#include <iterator>
#include <string>
#include <array>
#include <list>
using namespace std;

list<char> editor;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input_str;
    cin >> input_str;
    for (int i  = 0; i < input_str.size(); i++) {
        editor.push_back(input_str[i]);
    }

    auto current_idx = editor.end();
    int cnt;
    cin >> cnt;
    while (cnt-- > 0) {
        char command;
        cin >> command;
        char append_char;
        switch (command) {
        case 'P':
            cin >> append_char;
            current_idx = editor.insert(current_idx, append_char);
            current_idx++;
             break;

        case 'B':
            if (editor.begin() == current_idx) {
                break;
            }

            --current_idx;
            current_idx = editor.erase(current_idx);
            break;
        case 'D':
            if (editor.end() == current_idx) {
                break;
            }

            ++current_idx;
            break;
        case 'L':
            if (editor.begin() == current_idx) {
                break;
            }

            --current_idx;
            break;

        default:
            break;
        }
    }

    for (auto& i : editor) {
        cout << i;
    }
    cout << '\n';
    return 0;
}