// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        helper("", 0 ,s, dict);
        return ans;
    }
    
    void helper(string sub_ans, int index , string s, vector<string>& dict) {
        if(index >= s.length()) {
            ans.push_back(sub_ans.substr(0, sub_ans.length()-1));
            return;
        }

        for(int i=index;i<s.length();i++) {
            string sub = s.substr(index, i + 1 - index);
            if(hasPerticularWord(sub, dict)) helper(sub_ans + sub + " ", i + 1, s, dict);
        }
    }
    
    bool hasPerticularWord(string word, vector<string>& dict) {
        for(string key : dict) if(word == key) return true;
        return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends