// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> umap;
        vector<int> ans;
        if(k > n) return ans;
        
        for(int i=0;i<k;i++) umap[A[i]]++;
        
        ans.push_back(umap.size());
        
        int left = 0;
        for(int i=k;i<n;i++) {
            umap[A[left]]--;
            umap[A[i]]++;
            
            if(!umap[A[left]]) umap.erase(A[left]);
            left++;
            ans.push_back(umap.size());
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends