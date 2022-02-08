// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<string> ans;
		vector<string> AllPossibleStrings(string s){
		    helper(0, "", s);
		    
		    sort(ans.begin(), ans.end());
		    
            return ans;
		}
		
		void helper(int index, string ds, string s) {
		    if(index == s.length()) {
		        if(ds != "") ans.push_back(ds);
		        return;
		    }
		    
		    helper(index + 1, ds + s[index], s);
		    helper(index + 1, ds, s);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends