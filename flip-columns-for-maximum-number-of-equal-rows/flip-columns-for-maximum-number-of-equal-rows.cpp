class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> counter;
        for(auto rows : matrix){
            bool complement = false;
            string s = "";
            if(rows[0] == 1) complement = true;
            
            for(auto el : rows){
                if(complement) s += to_string(el ^ 1);
                else s += to_string(el);
            }
            counter[s]++;
        }
        
        int maxi = 0;
        for(auto iterator : counter)
            if(maxi < iterator.second)
                maxi = iterator.second;
        
        return maxi;
    }
};