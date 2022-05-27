class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size(); 
        vector<int> ans(n, -1);
        set<int> mapDry;
        unordered_map<int, int> mpp; 
        for(int i=0;i<n;i++) {
            if(rains[i] == 0) {
                mapDry.insert(i);
                ans[i] = 1 ;
            }
            else {
                if(mpp.count(rains[i])) {
                    int lastIndex = mpp[rains[i]];
                    auto zeroIndex = mapDry.upper_bound(lastIndex);
                    if(zeroIndex == mapDry.end())
                        return {};
                    ans[*zeroIndex] = rains[i];
                    mapDry.erase(zeroIndex);
                }
                mpp[rains[i]] = i;
            }
        }
        
        return ans;
    }
};