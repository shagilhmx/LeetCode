class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //dfs
        int n = isConnected.size(), provinces = 0;
        vector<bool> vis(n, false);
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                provinces++;
                dfs(i, isConnected, n, vis);
            }
        }
        
        return provinces;
    }
    
    void dfs(int node, vector<vector<int>>& isConnected, int V, vector<bool>& vis) {
        vis[node] = true;
        
        for(int i=0;i<V;i++) {
            if(!vis[i] && isConnected[node][i] == 1)
                dfs(i, isConnected, V, vis);
        }
    }
}; 