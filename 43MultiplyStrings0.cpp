#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::reverse;

string multiply(string num1, string num2) {
    string num3;
    string num3_tmp;
    string padding_zero;
    int tmp1(0), tmp2(0), tmp4(0);

    if (num1.empty() || num2.empty())
    return num3;

    if((num1.size() == 1 && *num1.begin() == '0') ||(num2.size() == 1 && *num2.begin() =='0'))
        return "0";

    if (num1.size() < num2.size())
        swap(num1, num2);

    for (auto i = num2.rbegin(); i < num2.rend(); i++) {
        num3_tmp = padding_zero;
        tmp2 = 0;
        for (auto j = num1.rbegin(); j < num1.rend(); j++) {
            tmp1 = ((*i - '0') * (*j - '0') + tmp2) % 10;
            tmp2 = ((*i - '0') * (*j - '0') + tmp2) / 10;
            num3_tmp.push_back((char)(tmp1 + 48));
        }
        if (tmp2 != 0)
            num3_tmp.push_back((char)(tmp2 + 48));

        string::size_type k(0);
        tmp4 = 0;
        for (k = 0; k < num3.size(); k++) {
            int add_tmp = (num3[k] - '0') + (num3_tmp[k] -'0') + tmp4;
            num3[k] = (char)((add_tmp % 10) + 48);
            tmp4 = add_tmp / 10;
        }
        if (tmp4 == 0)
            num3 += num3_tmp.substr(k);
        else {
            while (k < num3_tmp.size() && tmp4 != 0) {
                num3.push_back((char)((num3_tmp[k] - '0' + tmp4) % 10 + 48));
                tmp4 = (num3_tmp[k] - '0' + tmp4) / 10;
                k++;
            }
            if (tmp4 == 0)
                num3 += num3_tmp.substr(k);
            else
                num3.push_back((char)(tmp4 + 48));
        }
        padding_zero.push_back('0');
    }

    reverse(num3.begin(), num3.end());
    return num3;
}

int main() {
    string num1 = "123456789";
    string num2 = "987654321";
    string num3 = multiply(num1, num2);
    std::cout << num3 << std::endl;
    return 0;
}
