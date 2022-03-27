// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[501][501];
    
    public:Solution() {
        memset(dp, -1, sizeof(dp));
    }
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            
            start++;
            end--;
        }
        return true;
    }
    
    int helper(string &str, int start, int end) {
        if(start >= end) return 0;
        
        if(isPalindrome(str, start, end)) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int res = INT_MAX, temp;
        
        for(int k=start;k<end;k++) {
            temp = 1 + helper(str, start, k) + helper(str, k + 1, end);
            
            res = min(res, temp);
        }
        
        return dp[start][end] = res;
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        
        return helper(str, 0, n - 1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends