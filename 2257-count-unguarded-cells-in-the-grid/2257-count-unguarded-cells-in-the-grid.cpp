class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //red = 2, green = 3.
        vector<vector<int>> dp (m, vector<int>(n, 3)); //all green cells
        
        ///mark guards and walls.
        for(auto wall : walls)
            dp[wall[0]][wall[1]] = 0;
        
        for(auto guard : guards)
            dp[guard[0]][guard[1]] = 1;
        
        //visit all cells.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(dp[i][j] == 1) {
                    for(int up=i-1;up>=0;up--) {
                        if(!check(dp, up, j))
                            break;
                        dp[up][j] = 2;
                    }
                    
                    for(int down=i+1;down<m;down++) {
                        if(!check(dp, down, j))
                            break;
                        dp[down][j] = 2;
                    }
                    
                    for(int left=j-1;left>=0;left--) {
                        if(!check(dp, i, left))
                            break;
                        dp[i][left] = 2;
                    }
                    
                    for(int right=j+1;right<n;right++) {
                        if(!check(dp, i, right))
                            break;
                        dp[i][right] = 2;
                    }
                }  
            }
        }
        
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j] == 3)
                    cnt++;
            }
        }
        
        return cnt;
    }
    
    bool check(vector<vector<int>>& dp, int i, int j) {
        if(i < 0 || i >= dp.size() || j < 0 || j >= dp[0].size() || dp[i][j] == 0 || dp[i][j] == 1)
            return false;
        return true;
    }
};