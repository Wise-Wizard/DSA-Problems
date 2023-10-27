class Solution
{
private:
    void solve(int k, int n, vector<int> &currComb, vector<vector<int>> &ans, int currDigit, int currSum)
    {
        // Base Case
        if (currSum == n && currComb.size() == k)
        {
            ans.push_back(currComb);
            return;
        }
        if (currSum > n || currComb.size() >= k)
            return;
        for (int i = currDigit; i <= 9; i++)
        {
            currComb.push_back(i);
            currSum += i;
            solve(k, n, currComb, ans, i + 1, currSum);
            currComb.pop_back();
            currSum -= i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> currComb;
        vector<vector<int>> ans;
        solve(k, n, currComb, ans, 1, 0);
        return ans;
    }
};