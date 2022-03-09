// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        bool flag;
        vector<int> table;
        
        for(int i=M;i<=N;i++) {
            flag = false;
            for(int j=2;j<=sqrt(i);j++) {
                if(i % j == 0) {
                    flag = true;
                    break;
                }
            }
            
            if(flag == false && i != 1 && i != 0) table.push_back(i);
        }
        return table;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends