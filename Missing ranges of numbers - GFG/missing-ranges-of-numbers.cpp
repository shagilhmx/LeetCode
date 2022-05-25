// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string findMissing(int arr[], int n) {
        // code here
        sort(arr, arr + n);
        string ans = "";
        if(arr[0] == 0 && n == 1)
            return "-1";
        if(arr[0] == 1 && n == 1)
            return "0";
            
        if(arr[0] != 0) {
            int x = arr[0] - 1;
            if(x > 0)
                ans += "0-" + to_string(x) + ' ';
        }
        
        if(arr[0] == 1)
            ans += "0 ";
        
        for(int i=0;i<n-1;i++) {
            int start = arr[i] + 1;
            int end = arr[i + 1] - 1;
            if(start < end)
                ans += to_string(start) + "-" + to_string(end) +' ';
            if(end == start)
                ans += to_string(end) + ' ';
        }
        
        if(ans == "")
            return "0";
            
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends