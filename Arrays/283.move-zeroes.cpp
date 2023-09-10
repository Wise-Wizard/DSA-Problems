// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            if (nums[i] == 0)
            {
                count++;
                // deleting the element from vector
                nums.erase(nums.begin() + i);
                i--;
                // The length gets decresed after erasing each element
                length--;
            }
        }

        for (int i = 0; i < count; i++)
        {
            // inserting the zero into vector
            nums.push_back(0);
        }
        cout << "array after shifting zeros to right side: "
             << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            // printing desired vector
            cout << nums[i] << " ";
        }
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 2, 0, 4, 5, 6};
    sol.moveZeroes(nums);
    return 0;
}