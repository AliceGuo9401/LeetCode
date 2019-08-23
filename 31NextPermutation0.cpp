#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i(0), j(0), rear(nums.size() - 1);
    while (nums[rear - i] <= nums[rear - i - 1] && i < nums.size() - 1)
        ++i;
    ++i;                                          //借助“树”思考
    if ( i != nums.size()) {
        while (nums[rear - j] <= nums[rear - i])
            ++j;                                  //找到最小的大于nums[rear - i]的元素
        int temp = nums[rear - j];
        nums[rear - j] = nums[rear - i];
        nums[rear - i] = temp;
    }
    sort(nums.end() - i, nums.end());
    return ;
}

int main() {
    vector<int> nums{2, 1, 3};
    nextPermutation(nums);
    for (auto num : nums)                         //C++11标准范围for语句，P114
        cout << num << ' ';
    return 0;
}
