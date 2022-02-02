class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        helperSum(0, target, candidates, ds);
        return ans;
    }
    
    void helperSum(int index, int target, vector<int>& candidates, vector<int>& ds) {
        if(index >= candidates.size()) {
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        
        if(candidates[index] <= target) {
            ds.push_back(candidates[index]);
            helperSum(index, target - candidates[index], candidates, ds);
            ds.pop_back();
        }
        
        helperSum(index + 1, target, candidates, ds);
    }
};