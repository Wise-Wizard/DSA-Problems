// 26. Remove Duplicates from Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> removeDuplicates(vector<int> &nums)
    {
        vector<int> new_vec;
        unordered_map<int, int> m;
        for (auto num : nums)
        {
            m[num]++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            cout<<it->first;
            new_vec.push_back((it->first));
        }
        return new_vec;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 4, 4};
    sol.removeDuplicates(nums);
    return 0;
}