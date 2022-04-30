class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x = max(rec1[0], rec2[0]);
        int y = max(rec1[1], rec2[1]);
        int x_ = min(rec1[2], rec2[2]);
        int y_ = min(rec1[3], rec2[3]);
        
        if(x < x_ && y < y_)
            return true;
        return false;
    }
};