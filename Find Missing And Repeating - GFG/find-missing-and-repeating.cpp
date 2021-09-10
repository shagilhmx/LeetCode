// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_map<int, bool> umap;
        int* ans = (int*)malloc(2*sizeof(int)); 
        for(int i=0;i<n;i++){
            if(umap.find(arr[i]) == umap.end())
                umap[arr[i]] = true;
            else
                ans[0] = arr[i];
        }
        for(int i=1;i<=n;i++){
            if(umap.find(i) == umap.end())
                ans[1] = i;
        }
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends