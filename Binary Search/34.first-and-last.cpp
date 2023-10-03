#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int mid = l + (r-l)/2;
    vector<int> solution;
    while(l<=r){
        if(nums[mid] == target){
            int i = 1;
            solution.push_back(mid);
            while(nums[mid-i] == target || nums[mid+i] == target){
                if(nums[mid-i]==target){
                     solution.push_back(mid-i);
                 }
                 if(nums[mid+i]==target){
                    solution.push_back(mid+i);
                 }           
                i++;
            }
            return solution;
            }
            else if(target > nums[mid]){
                l = mid + 1;
            }
             else{
                r = mid - 1;
            }
            mid = l + (r-l)/2;
    }
     return {-1, -1};   
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 18, 28, 69, 69, 69, 72};
    vector<int> range = sol.searchRange(nums, 69);
    cout<<range[0]<<range.size();
    return 0;
}