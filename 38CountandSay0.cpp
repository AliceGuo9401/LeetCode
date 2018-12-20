#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    string s("1");                                         //string str("value");
    for( int i = 0; i < n - 1; ++i) {
        string tempS;                                      //空串
        for (int j = 0; j < s.size(); ++j) {
            char tempChar(s[j]);
            char tempCount('1');
            while (s[j + 1] == s[j] && j < s.size() - 1) {
                ++tempCount;
                ++j;
            }
            tempS = tempS + tempCount + tempChar;          //string + char，返回连接后的结果
        }
        s = tempS;
    }
    return s;
}

int main() {
    string s(countAndSay(8));
    cout << s;
    return 0;
}
