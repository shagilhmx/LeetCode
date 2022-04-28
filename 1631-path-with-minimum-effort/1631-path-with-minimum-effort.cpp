class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        
        pq.push({0, {0, 0}}); //value and cordinates.
        dis[0][0] = 0;
        
        while(!pq.empty()) {
            auto info = pq.top();
            int x = info.second.first;
            int y = info.second.second;
            int currDis = info.first;
            pq.pop();
            
            if(x == n - 1 && y == m - 1)
                return currDis;
            
            for(int i=0;i<4;i++) {
                int dx = x + dir[i].first;
                int dy = y + dir[i].second;
                if(dx >= 0 && dy >= 0 && dx < n && dy < m) {
                    int newDis = max(currDis, abs(heights[dx][dy] - heights[x][y]));
                    if(newDis < dis[dx][dy]) {
                        dis[dx][dy] = newDis;
                        pq.push({newDis, {dx, dy}});
                    }
                }
            }
        }
        return 0;
    }
};