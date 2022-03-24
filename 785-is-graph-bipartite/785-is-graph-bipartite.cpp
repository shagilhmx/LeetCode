class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        /*
        we are getting the adj list.
        
        which will be of the form, 0 -> {1, 2, 3}, 1 -> {0, 2}, 2 -> {0. 1, 3}
        and 3 -> {0, 2}.
        */
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++)
            if(color[i] == -1)
                if(!bfsCheck(graph, i, color)) return false;
        
        return true;
    }
    
    bool bfsCheck(vector<vector<int>>& graph, int node, vector<int>& color) {
        queue<int> q;
        q.push(node);
        
        color[node] = 1;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(int u : graph[curr]) {
                if(color[u] == -1) {
                    color[u] = 1 - color[curr];
                    q.push(u);
                }
                else if(color[u] == color[curr]) return false;
            }
        }
        return true;
    }
};