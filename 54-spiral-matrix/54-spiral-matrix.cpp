class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size()-1, c = matrix[0].size()-1;
        int low = 0, left = 0, high = r, right = c, dir = 0;
        vector<int> res;
        while(low <= high && left <= right){
            if(dir == 0){
                for(int i=left;i<=right;i++) res.push_back(matrix[low][i]);
                low++;
            }
            else if(dir == 1){
                for(int i=low;i<=high;i++) res.push_back(matrix[i][right]);
                right--;
            }
            else if(dir == 2){
                for(int i=right;i>=left;i--) res.push_back(matrix[high][i]);
                high--;
            }
            else if(dir == 3){
                for(int i=high;i>=low;i--) res.push_back(matrix[i][left]);
                left++;
            }
            dir = (dir + 1)%4;
        }
        return res;
    }
};