#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void recursion(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int index)
    {
        if (index >= nums.size())
        {
            if (find(ans.begin(), ans.end(), output) == ans.end())
            {
                ans.push_back(output);
            }
            return;
        }

        output.push_back(nums[index]);
        recursion(nums, ans, output, index + 1);
        output.pop_back();

        // exclude
        recursion(nums, ans, output, index + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        recursion(nums, ans, output, 0);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    return 0;
}