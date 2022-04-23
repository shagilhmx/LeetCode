class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //simple bfs
        int n = maze.size(), m = maze[0].size();
        
        vector<pair<int, int>> dir{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto front = q.front();
                q.pop();
                
                for(auto d : dir) {
                    int dx = front.first + d.first, dy = front.second + d.second;
                    
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] == '.' && !visited[dx][dy]) {
                        if(dx == 0 || dy == 0 || dx == n - 1 || dy == m - 1)
                            return steps;
                        q.push({dx, dy});
                        visited[dx][dy] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};