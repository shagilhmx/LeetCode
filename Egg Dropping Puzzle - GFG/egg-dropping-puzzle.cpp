// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int dp[201][201];
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return EggDrop(n, k);
    }
    int EggDrop(int n, int k) 
    {
        if(k == 0 || k == 1) return k;
        if(n == 1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int minValue = INT_MAX, temp, i;
        
        for(i=1;i<=k;i++) {
            int lhs = dp[n - 1][i - 1] != -1 ? dp[n - 1][i - 1] : EggDrop(n - 1, i - 1);
            int rhs = dp[n][k - i] != -1 ? dp[n][k - i] : EggDrop(n, k - i);
            temp = 1 + max(lhs, rhs);
            minValue = min(minValue, temp);
        }
        
        return dp[n][k] = minValue;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends