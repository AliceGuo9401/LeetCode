#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int length(1), k(0);
    for (int i = 0; i < nums.size(); ) {
        int j(i + 1);
        while (j < nums.size()) {
            if (nums[j] == nums[i])
                ++j;
            else if (nums[j] != nums[i]) {
                ++length;
                nums[k + 1] = nums[j];    //1, 1, 2 -> 1, 2, 2
                k = k + 1;
                break;
            }
        }
        i = j;
    }
    return length;
}
int main() {
    vector<int> nums{0, 0, 1, 1, 2, 2, 3, 3, 4};
    int length = removeDuplicates(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    cout << length;
    return 0;
}
