/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
    
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;
        
        int mid = left + (right - left) / 2;
        int count = 0;
        
        count += mergeSortAndCount(nums, left, mid); // Count in left subarray
        count += mergeSortAndCount(nums, mid + 1, right); // Count in right subarray
        
        // Merge and count in the combined subarray
        int i = left, j = mid + 1;
        while (i <= mid) {
            while (j <= right && static_cast<long long>(nums[i]) > 2LL * nums[j]) {
                j++;
            }
            count += (j - mid - 1);
            i++;
        }
        
        // Merge the two sorted subarrays
        vector<int> merged(right - left + 1);
        int p = 0;
        i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                merged[p++] = nums[i++];
            } else {
                merged[p++] = nums[j++];
            }
        }
        while (i <= mid) {
            merged[p++] = nums[i++];
        }
        while (j <= right) {
            merged[p++] = nums[j++];
        }
        for (int k = 0; k < merged.size(); k++) {
            nums[left + k] = merged[k];
        }
        
        return count;
    }
};

// @lc code=end

