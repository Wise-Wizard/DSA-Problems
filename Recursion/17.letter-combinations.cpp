#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string digits, string output, int index, vector<string> mapping, vector<string> &ans) {
        // Base case
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index + 1, mapping, ans);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int index = 0;
        vector<string> mapping = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = "";
        vector<string> ans;
        solve(digits, output, index, mapping, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "23";
    vector<string> ans = sol.letterCombinations(s);
    cout << ans[0];
    return 0;
}