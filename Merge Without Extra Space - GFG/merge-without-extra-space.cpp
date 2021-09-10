// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        int nextGap(int gap){
            if (gap <= 1)
                return 0;
            return (gap/2)+(gap%2);
        }
    public:
        //Function to merge the arrays.
        void merge(long long ar1[], long long ar2[], int n, int m) 
        { 
            int i,j, gap = n+m;
            for(gap = nextGap(gap); gap>0; gap = nextGap(gap)){
                for(i=0;i+gap<n;i++){
                    if(ar1[i] > ar1[i+gap])
                        swap(ar1[i], ar1[i+gap]);
                }
                
                for(j=gap>n?gap-n:0;i<n && j<m; i++,j++){
                    if(ar1[i] > ar2[j])
                        swap(ar1[i], ar2[j]);
                }
                
                if(j < m){
                    for(j=0; j+gap<m; j++){
                        if(ar2[j] > ar2[j+gap])
                            swap(ar2[j], ar2[j+gap]);
                    }
                }
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends