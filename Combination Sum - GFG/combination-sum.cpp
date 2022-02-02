// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> ds;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        helperSum(0, B, A, ds);
        return ans;
    }
    
    void helperSum(int index, int target, vector<int>& arr, vector<int>& ds) {
        if(index >= arr.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        if(arr[index] <= target) {
            ds.push_back(arr[index]);
            helperSum(index, target - arr[index], arr, ds);
            ds.pop_back();
        }
        
        helperSum(index + 1, target, arr, ds);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends