#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[r])
            {
                ans = min(ans, nums[l]);
                return ans;
            }
            else if (nums[l] <= nums[mid])
            {
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 18, 28, 35, 45, 69, 72};
    int num = sol.findMin(nums);
    cout << num;
    return 0;
}