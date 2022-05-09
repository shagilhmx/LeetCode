// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    /*
    1.Traverse the array, Ignore the elements which are greater than n and less than 1.
    2.While traversing check a[i]!=a[a[i]-1] if this condition hold true or not .
    3.If the above condition is true then swap a[i], a[a[i] – 1]  && swap until a[i] != a[a[i] – 1]  condition will fail .
    4.Traverse the array and check whether a[i] != i + 1 then return i + 1.
    5.If all are equal to its index then return n+1.
    */
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++)
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
                
        for(int i=0;i<n;i++)
            if(arr[i] != i + 1)
                return i + 1;
                
        return n + 1;
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends