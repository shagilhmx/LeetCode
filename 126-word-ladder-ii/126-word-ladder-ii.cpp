class Solution {
	 vector<vector<string>> ans;
public:
    void helper(string start,string end,unordered_set<string> &st){
	    queue<vector<string>> q;
		q.push({start});  //storing path
		bool flag=false;
		while(!q.empty()){
		    int n=q.size();
			while(n--) {
			    vector<string> curr_path=q.front(); 
				q.pop();
				if(curr_path.back()==end){
				    ans.push_back(curr_path);
					flag=true;  //if we got our answer then we need to consider
					// only this level of bfs
					continue;
				 }
				 string temp=curr_path.back();
				 st.erase(temp);
				 for(int j=0;j<temp.length();j++){
					string curr=temp;
					for(int i=0;i<26;i++){
					    curr[j]=i+'a';
						if(st.find(curr)!=st.end()){ 
						    curr_path.push_back(curr);
							q.push({curr_path});
							curr_path.pop_back();
						}
				    }
				}
		    }
		    if(flag)  break;
	    }
	}
    
    vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto &it: wordList) st.insert(it);

        if(st.find(end)==st.end()) return {};
        helper(start,end,st);
        return ans;
        }
    };