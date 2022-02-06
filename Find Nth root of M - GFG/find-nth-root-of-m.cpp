// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long NthRoot(long long n, long long m)
	{
	    //n is exponential and m is the number.
	    if(n == 1 || m == 1) return m; 
        long long start = 1;
        long long end = m;

        while(start <= end) {
            long long mid = start + (end - start)/2;
            if(solve(mid, n, m) == m) return mid;
            else if(solve(mid, n, m) <= m) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
	}
	
	int solve(int num, int n, int m) {
	    unsigned long long ans = 1;
	    for(int i=1;i<=n;i++) {
	        ans *= num;
	        if(ans > m)
	            return m + 2;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends