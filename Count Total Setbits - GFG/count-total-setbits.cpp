// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N){
        int ans = 0;
        
        ans = solve(N);
        
        return ans;
    }
    
    int solve(int n) {
        if(n == 0) return 0;
        
        int x = 0;
        
        while((1 << x) <= n) {
            x++;
        }
        x = x - 1;
        
        int bitsUpto2RaiseToX = x * (1 << (x - 1));
        int msb2RaiseXToN = n - (1 << x) + 1;
        int rest = n - (1 << x);
        int ans = bitsUpto2RaiseToX + msb2RaiseXToN + countBits(rest);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends