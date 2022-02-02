class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> listOfData = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        
        helper(listOfData, ds, k, n, 0);
        
        return ans;
    }
    
    void helper(vector<int>& list, vector<int>& ds, int targetSize, int target, int index) {
        if(target < 0 || ds.size() > targetSize) return;
        
        if(target == 0 && ds.size() == targetSize) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=index;i<list.size();i++) {
            if(list[i] > target) break;
            ds.push_back(list[i]);
            helper(list, ds, targetSize, target - list[i], i + 1);
            ds.pop_back();
        }
    }
};