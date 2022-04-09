class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        
        for(int el : nums)
            mpp[el]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto itr : mpp)
            pq.push({itr.second, itr.first});
        
        for(int i=0;i<k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};