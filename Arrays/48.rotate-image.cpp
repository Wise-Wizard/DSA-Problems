/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int k = 0;
        vector<int> values;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
               values.push_back(matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
               matrix[i][j] = values[k];
               k++;
            }
        }
    }
};
// @lc code=end

