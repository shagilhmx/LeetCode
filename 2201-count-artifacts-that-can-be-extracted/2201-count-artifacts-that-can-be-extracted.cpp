class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        for(auto el : dig) visited[el[0]][el[1]] = 1;
        
        int count = 0;
        for(auto artifact : artifacts) {
            int r1 = artifact[0];
            int c1 = artifact[1];
            int r2 = artifact[2];
            int c2 = artifact[3];
            
            bool flag = true;
            for(int i=r1;i<=r2;i++) {
                for(int j=c1;j<=c2;j++) {
                    if(!visited[i][j]) flag = false;
                }
            }
            
            if(flag) count++;
        }
        return count;
    }
};