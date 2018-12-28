#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() < 3) return 0;

    int left(0), right(height.size() - 1), rainWater(0), s(0);
    while (height[left] == 0 && left <= right)
        ++left;
    while (height[right] == 0 && left <= right)
        --right;

    int flag(0);
    while (left <= right) {
        if (height[left] == height[right]) {
            s += (height[left] - flag) * (right - left + 1);
            flag = height[left];
            do
                ++left;
            while (height[left] <= flag && left <= right);
            do
                --right;
            while (height[right] <= flag && left <= right);
        }
        else if (height[left] < height[right]) {
            s += (height[left] - flag) * (right - left + 1);
            flag = height[left];
            do
                ++left;
            while (height[left] <= flag && left <= right);
        }
        else if (height[left] > height[right]) {
            s += (height[right] - flag) * (right - left + 1);
            flag = height[right];
            do
                --right;
            while (height[right] <= flag && left <= right);
        }
    }
    for (auto i : height)
        rainWater += i;
    rainWater = s - rainWater;
    return rainWater;
}

int main() {
    vector<int> height{4, 2, 0, 3, 2, 5};
    int rain = trap(height);
    cout << rain;
    return 0;
}
