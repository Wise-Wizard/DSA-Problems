class Solution
{
private:
    bool isPalindrome(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

private:
    void partition(string s, vector<vector<string>> &ans, vector<string> &output, int index)
    {
        // Base Case
        if (index == s.size())
        {
            ans.push_back(output);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                output.push_back(s.substr(index, i - index + 1));
                partition(s, ans, output, i + 1);
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> output;
        partition(s, ans, output, 0);
        return ans;
    }
};
