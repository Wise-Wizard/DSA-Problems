#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string temp;
            while (i < n && s[i] != ' ') {
                temp.push_back(s[i]);
                i++;
            }
            if (!temp.empty()) {
                res.push_back(temp);
                count++;
            }
        }

        string reversed;
        for (int i = count - 1; i >= 0; i--) {
            reversed += res[i];
            if (i > 0) {
                reversed += ' ';
            }
        }

        return reversed;
    }
};

int main() {
    Solution sol;
    string s = "a good   example";
    string ans = sol.reverseWords(s);
    cout << ans;
    return 0;
}
