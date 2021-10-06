// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;
        int last;
        sort(arr, arr+n);
        for(int i=0;i<n;i++){
            if(arr[i] == arr[i+1] && arr[i] != last){
                res.push_back(arr[i]);
                last = arr[i];
            }
        }
        if(res.size() == 0) return {-1};
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends