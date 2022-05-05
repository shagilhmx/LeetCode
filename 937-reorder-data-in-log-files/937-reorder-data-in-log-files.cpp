class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<pair<string, string>> reorderedFile;
        
        for(int i=0;i<n;i++) {
            string s = logs[i];
            string temp = "";
            int j = 0;
            while(s[j] != ' ') {
                temp += s[j];
                s.erase(s.begin());
            }
            temp += s[j];
            s.erase(s.begin());
            
            if(isalpha(s[0]))
                reorderedFile.push_back({s, temp});
        }
        
        sort(reorderedFile.begin(), reorderedFile.end());
        vector<string> ans;
        
        for(int i=0;i<reorderedFile.size();i++)
            ans.push_back(reorderedFile[i].second + reorderedFile[i].first);
        
        for(int i=0;i<n;i++) {
            string s = logs[i];
            int j = 0;
            while(s[j] != ' ')
                s.erase(s.begin());
            s.erase(s.begin());
            
            if(isdigit(s[0]))
                ans.push_back(logs[i]);
        }
        
        return ans;
    }
};