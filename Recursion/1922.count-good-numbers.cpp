#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodNumbers(long long n) {
        //odd-prime: 2, 3, 5, 7
        //even-even: 0, 2, 4, 6, 8
        if(n%2==0){
            return pow(4, n/2)*pow(5, n/2);
        }
        else{
            return pow(4, n/2)*pow(5, n/2)*4;
        }
    } 
};
int main()
{
    Solution sol;
    long long n = 1;
    long long ans = sol.countGoodNumbers(n);
    cout<<ans;
    return 0;
}