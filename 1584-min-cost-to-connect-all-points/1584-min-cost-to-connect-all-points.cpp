class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int wt = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }
        
        //prims algorithm
        int res = 0;
        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        //{cost, i}
        
        while(vis.size() < n) {
            auto front = pq.top();
            pq.pop();
            
            if(!vis.count(front.second)) {
                res += front.first;
                vis.insert(front.second);
                
                for(auto u : adj[front.second]) {
                    if(!vis.count(u.second))
                        pq.push({u.first, u.second});
                }
            }
        }
        
        return res;
    }
};