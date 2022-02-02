// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> res;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        compute(arr, 0, 0, N);
        return res;
    }

    void compute(vector<int> &arr, int sum, int index, int size) {
        if(index >= size) {
            res.push_back(sum);
            return;
        }
        compute(arr, sum + arr[index], index + 1, size);
        compute(arr, sum, index + 1, size);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends