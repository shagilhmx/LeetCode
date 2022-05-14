class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkastra.
        vector<pair<int, int>> adj[n + 1];
        
        //create a adj matrix.
        for(auto &v : times)
            adj[v[0]].push_back({v[1], v[2]});
        
        int ans = 0;
        vector<int> dist(n + 1, INT_MAX);
        //{dist, node}
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        dist[k] = 0;
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            for(auto &u : adj[node.second]) {
                if(dist[u.first] > dist[node.second] + u.second) {
                    dist[u.first] = dist[node.second] + u.second;
                    pq.push({dist[u.first], u.first});
                }
            } 
        }
        
        for(int i=1;i<=n;i++) {
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};