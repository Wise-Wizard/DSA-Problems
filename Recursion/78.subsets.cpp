#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> output)
    {
        // Base Case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        // Exclude
        solve(nums, index + 1, ans, output);
        // Include
        output.push_back(nums[index]);
        solve(nums, index + 1, ans, output);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, index, ans, output);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2};
    vector<vector<int>> ans = sol.subsets(nums);
    return 0;
}