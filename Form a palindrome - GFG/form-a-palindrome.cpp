// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int lcs(string &s, string &t, int n, int m) {
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

int longestPalindromeSubseq(string &s) {
        /*create a copy of the original string and reverse it,
        now do the longest common Subsequence on the two string,
        i.e get the longest common subsequence of the two strings.
        Thats the ans;
        */
        int n = s.length();
        string temp = s;
        reverse(temp.begin(), temp.end());
        
        return lcs(s, temp, n, n);
    }
    
  public:
    int countMin(string str){
    //complete the function here
    return str.length() - longestPalindromeSubseq(str);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends