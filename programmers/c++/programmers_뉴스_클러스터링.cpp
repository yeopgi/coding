#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> vStr1, vStr2;

void split(stringstream ss, string token, char delimeter, vector<string> v)
{
    while (getline(ss, token, delimeter)) {
        v.push_back(token);
    }
}


int solution(string str1, string str2) {
    int answer = 0;
    stringstream ss(str1);
    string token;
    split(ss, token, )


    return answer;
}