#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};
    vector<vector<int>> quadruplets;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
        if (i != 0 && nums[i] == nums[i - 1])
                continue;

        int target1 = target - nums[i];
        for (int j = i + 1;j < nums.size() - 2; ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

            int target2 = target1- nums[j];
            int k(j + 1),l(nums.size() - 1);
            while (k < l) {
                if (nums[k] + nums[l] < target2)
                    ++k;
                else if (nums[k] + nums[l] == target2) {
                    quadruplets.push_back({nums[i], nums[j], nums[k], nums[l]});
                    do
                        ++k;
                    while (nums[k] == nums[k - 1]);
                    do
                        --l;
                    while (nums[l] == nums[l + 1]);
                }
                else if (nums[k] + nums[l] > target2)
                    --l;
            }
        }
    }
    if (quadruplets.empty())
        return {};
    else if (!quadruplets.empty())
        return quadruplets;
}
int main() {
    vector<int> nums{-1,0,-5,-2,-2,-4,0,1,-2};
    int target(-9);
    vector<vector<int>> solutionSet = fourSum(nums, target);
    for (auto solution : solutionSet) {
        for (auto sol : solution)
            cout << sol << ' ';
        cout << endl;
    }
    return 0;
}
