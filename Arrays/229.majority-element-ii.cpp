/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size()/3;
        for(auto num : nums){
            m[num]++;
        }
        nums.clear();
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second>n){
                nums.push_back(it->first);
            }
        }
        return nums;
    }
};
// @lc code=end

