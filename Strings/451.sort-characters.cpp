#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (char ch: s) map[ch]++;
        
        priority_queue<pair<int, char>> pq;
        for (auto pair: map) {
            pq.push({pair.second, pair.first});
        }

        string ans;
        pair<int, char> curr;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            ans.append(curr.first, curr.second);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    string ans = sol.frequencySort(s);
    cout<<ans;
    return 0;
}