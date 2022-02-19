class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> vis;
        int totalOranges = 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 2) vis.push({i, j}); //pushing the rotten oranges.
                if(grid[i][j] != 0) totalOranges++; //total Oranges count.
            }
        }
        
        int cnt = 0;
        
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
                         // left,   right,    up,     down. 
        int days = 0; //count number of days.
            
        while(!vis.empty()) {
            int size = vis.size(); //size of queue.
            cnt += size; //keeping count of rotton oranges. 
            
            while(size--) {
                //rotten oranges cordinates.
                int x = vis.front().first, y = vis.front().second;
                vis.pop();
                
                for(int i=0;i<4;i++) {
                    //tranverse directions.
                    int row = x + directions[i][0];
                    int col = y + directions[i][1];
                    
                    if(row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        vis.push({row, col});
                    }
                }
            }
            if(!vis.empty()) days++; //check if the queue still have rotten oranges and increment days value.
        }
        return (totalOranges == cnt) ? days : -1;
    }
};