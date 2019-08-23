#include <iostream>
#include <cmath>
using namespace std;
int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT32_MIN && divisor == -1)) return INT32_MAX; //int占4个字节
    long long dividendTemp(fabs(dividend)), divisorTemp(fabs(divisor));   //double占8个字节。fabs()函数的函数原型：double fabs(double x);
    long long multiple(1);                                                //long long占8个字节
    long long quotient(0);
    while (0 < dividendTemp) {
        while (divisorTemp <= dividendTemp) {          //10 > 3  multiple=1; 10 > 6 multiple=2; 10 < 12 multiple=3;记录quotient+=2；(*)
            divisorTemp = divisorTemp << 1;           
            multiple = multiple << 1;
        }
        divisorTemp = divisorTemp >> 1;
        multiple = multiple >> 1;
        quotient = quotient + multiple;
        
        dividendTemp = dividendTemp - divisorTemp;     //10 - 6 = 4;重复(*)过程
        divisorTemp = fabs(divisor);
        multiple = 1;
    }
    return (dividend < 0) ^ (divisor < 0) ? -quotient : quotient;
}

int main() {
    int dividend(-2147483648), divisor(1);
    int quotient = divide(dividend, divisor);
    cout << quotient;
    return 0;
}
