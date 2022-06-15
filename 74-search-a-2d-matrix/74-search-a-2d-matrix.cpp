class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int n = matrix.size(), m = matrix[0].size();
        vector<int> temp;
        
        for(int i=0;i<n;i++) {
            if(target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                temp = matrix[i];
                break;
            }
        }
        
        int start = 0, end = temp.size()-1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(temp[mid] == target)
                return true;
            
            else if(temp[mid] < target)
                start = mid + 1;
            
            else
                end = mid - 1;
        }
        
        return false;
    }
};