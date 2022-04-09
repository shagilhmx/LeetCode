// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.length();
        int start = 0, end = 0;
        int ans = INT_MIN;
        
        bool dp[n][n];
        
        for(int gap=0;gap<n;gap++) {
            for(int i=0, j=gap;j<n;i++, j++) {
                if(gap == 0) dp[i][j] = true; //if only one character, i.e gap is zero.
                /* if two character, i.e 
                gap is 1, we check if both the character are same if yes return 2, otherwise                 1.*/
                else if(gap == 1) dp[i][j] = s[i] == s[j] ? true : false; 
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = true; //2 + midPart(str).
                    }
                    else {
                        dp[i][j] = false; // max(c1m, mc2).
                    }
                }
                if(ans < j - i && dp[i][j]) {
                    ans = j - i;
                    start = i;
                    end = j - i + 1;
                }
            }
        }
        return s.substr(start, end);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends