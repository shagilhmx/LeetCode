class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> adj[n];
        vector<bool> vis(n, false);
        
        for(auto v : pairs) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        for(int i=0;i<n;i++) {
            vector<int> index;
            vector<char> letters;
            
            if(!vis[i])
                dfs(s, i, adj, index, letters, vis);
            
            sort(index.begin(), index.end());
            sort(letters.begin(), letters.end());
            
            for(int j=0;j<index.size();j++)
                s[index[j]] = letters[j];
        }
        
        return s;
    }
    
    void dfs(string& s, int& u, vector<int> *adj, vector<int>& index, vector<char>& letters, vector<bool>& vis) {
        vis[u] = true;
        index.push_back(u);
        letters.push_back(s[u]);
        
        for(int v : adj[u])
            if(!vis[v])
                dfs(s, v, adj, index, letters, vis);
    }
};