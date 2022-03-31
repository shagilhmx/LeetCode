// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr, arr + n);
	    int cnt = 0;
	    
	    for(int i=0;i<n-1;i++) {
	        int start = i + 1;
	        int end = n - 1;
	        while(start <= end) {
	            if(arr[i] + arr[start] + arr[end] >= sum)
	                end--;
	            else {
	                start++;
	                cnt += (end - start + 1);
	            }
	        }
	    }
	    return cnt;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends