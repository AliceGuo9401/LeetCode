#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    
    int i(0), j(nums.size() - 1);               //i初始化为0，j初始化为nums.size() - 1  从两端向中间处理
    for (i = 0; i < j; ) {  /**/
        if (nums[i] != val)
            ++i;
        else if (nums[i] == val) {              //当num[i] == val时，把j标识的元素交换到i标识的元素，--j
            nums[i] = nums[j];
            --j;
        }
    }
    if (nums[i] != val)
        return i + 1;
    else if (nums[i] == val)
        return i;
}

int main() {
    vector<int> nums{0, 1, 2, 2, 2, 2, 2, 2};
    int val(2);
    int length = removeElement(nums, val);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    cout << length;
    return 0;
}
