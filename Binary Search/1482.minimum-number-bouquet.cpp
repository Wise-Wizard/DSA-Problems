#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleSolution(vector<int> &bloomDay, int mid, int m, int k)
    {
        int bouquets = 0;
        int flower_count = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                flower_count++;
                if (flower_count == k)
                {
                    bouquets++;
                    flower_count = 0;
                }
            }
            else
            {
                flower_count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int min = 1;
        int max = bloomDay[0];
        int ans = -1;
        for (int i = 1; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] > max)
            {
                max = bloomDay[i];
            }
        }

        int mid = min + (max - min) / 2;
        while (min <= max)
        {
            if (isPossibleSolution(bloomDay, mid, m, k))
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
    vector<int> nums = {1, 10, 3, 10, 2};
    int ans = sol.minDays(nums, 3, 2);
    cout << ans;
    return 0;
}