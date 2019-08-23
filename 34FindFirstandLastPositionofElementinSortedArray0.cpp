#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> positions{-1, -1};
    if (nums.empty()) return positions;

    int low(0), high(nums.size() - 1), mid(0);
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[low] == target && nums[high] == target) {positions[0] = low; positions[1] = high; return positions;}

        /*if (nums[low] == target) {
            positions[0] = low;
            while (low < high) {
                if (nums[mid] == target) {
                    positions[1] = mid;
                    low = mid + 1;
                }
                else if (nums[mid] > target)
                    high = mid - 1;
                mid = (low + high) / 2;
            }
            if (nums[high] == target)
                positions[1] = high;
            break;
        }

        if (nums[high] == target) {
            positions[1] = high;
            while (low < high) {
                if (nums[mid] == target) {
                    positions[0] = mid;
                    high = mid - 1;
                }
                else if (nums[mid] < target)
                    low = mid + 1;
                mid = (low + high) / 2;
            }
            if (nums[low] == target)
                positions[0] = low;
            break;
        }*/

        if (nums[mid] == target) {               
            int midL = (low + mid) / 2;
            int midH = (high+ mid) / 2;
            int midTemp(mid);
            while (nums[low] != target) {
                ++low;
                if (nums[low] == target) break;
                if (nums[midL] < target)
                    low = midL + 1;
                else if (nums[midL] == target)
                    midTemp = midL;
                midL = (low + midTemp) / 2;
            }
            positions[0] = low;
            midTemp = mid;
            while (nums[high] != target) {
                --high;
                if (nums[high] == target) break;
                if (nums[midH] > target)
                    high = midH - 1;
                else if (nums[midH] == target)
                    midTemp = midH;
                midH = (high + midTemp) / 2;
            }
            positions[1] = high;
            break;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
    }
    if (low == high && target != nums[low] || high == -1) return positions;
    return positions;
}

int main() {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 8, 10, 10};
    int target(4);
    vector<int> positions = searchRange(nums, target);
    for (auto i : positions)
        cout << i << ' ';
    return 0;
}
