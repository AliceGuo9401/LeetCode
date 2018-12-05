#include <iostream>
#include <string>

using namespace std;
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;

    int index(-1);
    for (int i = 0; i < haystack.size(); ++i) {
        while (haystack[i] != needle[0] && i < haystack.size())
            ++i;
        int k(i), counter(0), flag(0);
        for (int j = 0; j < needle.size() && k < haystack.size(); ) {
            if (haystack[k] == needle[j]) {
                ++counter;
                ++k;
                ++j;
            }
            else if (haystack[k] != needle[j]) {
                flag = 1;
                break;
            }
        }
        if (counter == needle.size() && flag == 0) {
            index = i;
            break;
        }
    }
    return index;
}
int main() {
    string haystack("aaaaa"), needle("bba");
    int index = strStr(haystack, needle);
    cout << index;
    return 0;
}
