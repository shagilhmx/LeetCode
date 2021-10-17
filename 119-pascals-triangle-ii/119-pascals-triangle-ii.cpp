class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        res.push_back(1);
        
        for(int i=0;i<rowIndex;i++){
            for(int j=res.size()-1;j>0;j--){
                res[j] = res[j-1] + res[j];
            }
            res.push_back(1);
        }
        return res;
    }
};