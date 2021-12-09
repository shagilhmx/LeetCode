class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int col = matrix[0].size()-1;
        vector<int> temp;
        for(auto x : matrix){
            if(target <= x[col]){
                temp = x;
                break;
            }
        }
        
        for(int value : temp)
            if(value == target) return true;
        return false;
    }
};