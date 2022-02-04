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
		    helper(0, S);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
		
		void helper(int index ,string s) {
		    if(index == s.length()) {
		        ans.push_back(s);
		        return;
		    }
		    
		    for(int i=index;i<s.length();i++) {
		        swap(s[index], s[i]);
		        helper(index + 1, s);
		        swap(s[index], s[i]);
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