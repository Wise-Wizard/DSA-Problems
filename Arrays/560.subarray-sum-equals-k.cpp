/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int count = 0;
        
        // Initialize the prefix sum with 0 and count with 1 (since sum of 0 can be achieved in the beginning)
        prefixSumCount[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // Check if (sum - k) exists in prefixSumCount, which means there is a subarray that sums to k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            // Increment the count of the current prefix sum
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};
// @lc code=end

