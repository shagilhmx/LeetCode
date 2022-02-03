// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
		vector<string>find_permutation(string S)
		{
		    string ds = "";
		    int freq[S.length()];
		    
		    for(int i=0;i<S.length();i++) freq[i] = 0;
		    
		    helper(S, freq, ds);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
		
		void helper(string s, int *freq, string ds) {
		    if(ds.length() == s.length()) {
		        ans.push_back(ds);
		        return;
		    }
		    
		    for(int i=0;i<s.length();i++) {
		        if(!freq[i]) {
		            ds += s[i];
		            freq[i] = 1;
		            helper(s, freq, ds);
		            freq[i] = 0;
		            ds.pop_back();
		        }
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends