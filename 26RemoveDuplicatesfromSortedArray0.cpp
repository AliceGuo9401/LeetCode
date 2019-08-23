#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    auto endUnique = unique(nums.begin(), nums.end());      //unique算法将相邻的重复项“消除”，并返回指向一个不重复元素之后的位置的迭代器
    int length(0);
    length = endUnique - nums.begin();
    return length;
}

int main() {
    vector<int> nums{1, 1, 2};
    int length = removeDuplicates(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    cout << length;
    return 0;
}
