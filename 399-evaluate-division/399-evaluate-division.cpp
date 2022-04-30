class Solution {
    //{start, {end, value}}
    unordered_map<string, unordered_map<string, double>> adj;
    unordered_set<string> vis;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        
        vector<double> ans;
        ans.reserve(m);
        
        for(int i=0;i<n;i++) {
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        
        for(int i=0;i<m;i++) {
            if(adj.count(queries[i][0]) == 0 || adj.count(queries[i][1]) == 0) {
                ans.push_back(-1);
                continue;
            }
            
            vis.insert(queries[i][0]);
            ans.push_back(dfs(queries[i][0], queries[i][1], vis));
            vis.clear();
        }
        
        return ans;
    }
    
    double dfs(const string &start, const string &end, unordered_set<string>& vis) {
        if(start == end)
            return 1;
        
        vis.insert(start);
        
        //check all adj edges.
        for(const auto &[nxt, wt] : adj[start]) {
            if(!vis.count(nxt)) {
                double res = dfs(nxt, end, vis);
                if(res != -1)
                    return res * wt;
            }
        }
        return -1;
    }
};
/*
as for the edges like a -> c = a -> b -> c : [(values_at(a) -> values_at(b)) + (values_at(b) -> values_at(c))].
*/