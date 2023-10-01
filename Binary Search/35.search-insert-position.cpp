#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() -1;
        int mid = start + (end/2 - start/2);
        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid + 1;
            }
             else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return mid;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 18, 28, 35, 45, 69, 72};
    int index = sol.search(nums, 70);
    cout<<index;
    return 0;
}