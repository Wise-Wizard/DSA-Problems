#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleSolution(vector<int> &nums, int threshold, int mid)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mid != 0)
            {
                if (nums[i] % mid == 0)
                {
                    sum += nums[i] / mid;
                }
                else
                {
                    sum += (nums[i] / mid + 1);
                }
            }
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int min = 0;
        int max = *max_element(nums.begin(), nums.end());
        int ans = max;
        int mid = min + (max - min) / 2;
        while (min <= max)
        {
            if (mid != 0 && isPossibleSolution(nums, threshold, mid))
            {
                ans = mid;
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
            mid = min + (max - min) / 2;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int ans = sol.smallestDivisor(nums, 6);
    cout << ans;
    return 0;
}