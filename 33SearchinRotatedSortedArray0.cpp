#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    
    int low(0), high(nums.size() - 1);
    int mid = (low + high) / 2;
    while (low < high) {
        if (nums[low] == target) return low;                    //nums: [1, 3, 2], target: 2
        if (nums[high] == target) return high;
        if (nums[mid] == target) return mid;

        if (nums[low] <= nums[mid]) {                           //[4, 5, 6, 7, 0, 1, 2]，以mid为中心，总存在一半是按非递减顺序排序的       
            if (nums[low] < target && target < nums[mid])       //在有序数组中，可以直接进行二分搜索
                high = mid - 1;
            else if (nums[mid] < target || target < nums[low])
                low = mid + 1;
        }
        else if (nums[mid] <= nums[high]){
            if (nums[mid] < target && target < nums[high])
                low = mid + 1;
            else if (target < nums[mid] || nums[high] < target)
                high = mid - 1;
        }
        
        mid = (low + high) / 2;
    }
    return nums[mid] == target ? mid : -1;                      //条件运算符? :
}

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target(1);
    int index = search(nums, target);
    cout << index;
    return 0;
}
