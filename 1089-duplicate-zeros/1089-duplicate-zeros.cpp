class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        for(int i : arr){
            if(i == 0) res.push_back(i);
            res.push_back(i);
        }
        int size = res.size();
        while(size--)
            if(size >= arr.size()) res.pop_back();
        arr = res;
    }
};