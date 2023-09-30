/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long left_product = 1;
        long long max_left_product = INT_MIN;
        long long right_product = 1;
        long long max_right_product = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                left_product = 1;
                if(max_left_product<0){
                    max_left_product = 0;
                }
                continue;
            }
            left_product = left_product * nums[i];
            max_left_product = max(left_product, max_left_product);
        }
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i]==0){
                right_product = 1;
                if(max_right_product<0){
                    max_right_product = 0;
                }
                continue;
            }
            right_product = right_product * nums[i];
            max_right_product = max(right_product, max_right_product);
        }
        return max(max_left_product, max_right_product);
    }
};
// @lc code=end

