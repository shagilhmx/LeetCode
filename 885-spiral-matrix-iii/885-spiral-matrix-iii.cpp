class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int n = rows*cols, step = 0;
        res.push_back({rStart, cStart});
        
        while(res.size() < n){
            step++;
            
            if(rStart >= 0 && rStart < rows)
                for(int i = max(cStart + 1, 0), lim = min(cStart + step + 1, cols);i < lim;i++) res.push_back({rStart, i});
            cStart += step;
            
            if(cStart >= 0 && cStart < cols)
                for(int j = max(rStart + 1, 0), lim = min(rStart + step + 1, rows); j < lim;j++) res.push_back({j, cStart});
            rStart += step;
            
            step++;
            
            if(rStart >= 0 && rStart < rows)
                for(int i = min(cStart - 1, cols - 1), lim = max(cStart - step, 0); i >= lim;i--) res.push_back({rStart, i});
            cStart -= step;
            
            if(cStart >= 0 && cStart < cols)
                for(int j = min(rStart - 1, rows - 1), lim = max(rStart - step, 0); j >= lim;j--) res.push_back({j, cStart});
            rStart -= step;
        }
        return res;
    }
};