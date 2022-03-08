// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> ans(arr, arr + n);
        
        long long minSum = 0;
        
        while(ans.size() >= 2) {
            long long firstNumber = ans.top();
            ans.pop();
            long long secondNumber = ans.top();
            ans.pop();
            
            minSum += (firstNumber + secondNumber);
            
            ans.push(firstNumber + secondNumber);
        }
        return minSum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends