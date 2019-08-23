#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int>& nums, int val) {
    int i(0);
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            ++i;
        }
        else if (nums[j] == val) {
            while (nums[j] == val && j < nums.size())
                ++j;
            if (j < nums.size()) {
                nums[i] = nums[j];
                ++i;
            }
            else if (j == nums.size())
                break;
        }
    }
    return i;
}

int main() {
    vector<int> nums{3, 2, 2, 3};
    int val = 3;
    int length = removeElement(nums, val);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << length;
    return 0;
}
