#include <iostream>
#include <cmath>

using namespace std;
int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT32_MIN && divisor == -1)) return INT32_MAX;
    /*注意：double, int的取值范围*/
    double i = log(fabs(dividend));   //double log(double x)函数，定义在cmath头文件中，底数为e。lnM - ln N = ln(M/N)
    double j = log(fabs(divisor));    //fabs函数，定义在cmath头文件中，求浮点数的绝对值
    int quotient = (int)exp(i - j);   //double exp(double x)函数，定义在cmath头文件中，e的x次方。e的ln(M/N)次方
    return dividend < 0 ^ divisor < 0 ? -quotient : quotient;       //条件运算符 ? :
}
int main() {
    int dividend(7), divisor(-3);
    int quotient = divide(dividend, divisor);
    cout << quotient;
    return 0;
}
