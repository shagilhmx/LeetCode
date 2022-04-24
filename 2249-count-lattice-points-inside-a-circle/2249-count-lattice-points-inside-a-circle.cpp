class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> ans;
        
        for(auto circle : circles) {
            int x = circle[0];
            int y = circle[1];
            int r = circle[2];
            int rSquare = r*r;
            
            for(int k=x-r;k<=x+r;k++) {
                for(int h=y-r;h<=y+r;h++) {
                    int xSquare = (x - k) * (x - k);
                    int ySquare = (y - h) * (y - h);
                    
                    if(xSquare + ySquare <= rSquare) {
                        pair<int, int> p;
                        p.first = k;
                        p.second = h;
                        ans.insert(p);
                    }
                }
            }
        }
        return ans.size();
    }
};