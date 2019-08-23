#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low(0), high(nums.size() - 1);
    int mid = (low + high) / 2;
    while (low <= high) {
        if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] == target)
            return mid;
        mid = (low + high) / 2;
    }
    return low;   /**/
}
int main() {
    vector<int> nums{ };
    int target(8);
    int index = searchInsert(nums, target);
    cout << index;
    return 0;
}
