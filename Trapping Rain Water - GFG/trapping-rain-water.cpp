// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long res = 0;
        long long left_max = 0, right_max = 0;
        int low = 0, high = n-1;
        
        while(low <= high) {
            if(arr[low] < arr[high]) {
                if(arr[low] > left_max) left_max = arr[low];
                else res += left_max - arr[low];
                low++;
            }
            else {
                if(arr[high] > right_max) right_max = arr[high];
                else res += right_max - arr[high];
                high--;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends