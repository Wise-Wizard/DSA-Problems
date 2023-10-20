class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;  // Initialize left pointer.
        int j = 0;  // Initialize right pointer.
        int maxLen = 0;  // Initialize the maximum length.

        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }

            // Check if k becomes negative.
            while (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }

            // Update the maximum length.
            maxLen = max(maxLen, j - i + 1);

            j++;  // Move the right pointer.
        }

        return maxLen;
    }
};
