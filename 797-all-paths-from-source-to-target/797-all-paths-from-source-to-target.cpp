class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ds;
        
        dfs(graph, 0, n - 1, ds);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, int start, int end, vector<int> path) {
        path.push_back(start);
        
        if(start == end) {
            ans.push_back(path);
        }
        
        for(auto u : graph[start])
            dfs(graph, u, end, path);
        
    }
};