class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), steps = 0;
        unordered_map<int, vector<int>> indicesOfValues;
        queue<int> q;
        unordered_set<int> vis;
        
        q.push(0);
        vis.insert(0);
        
        for(int i=0;i<n;i++)
            indicesOfValues[arr[i]].push_back(i); 
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto i = q.front();
                q.pop();
                
                if(i == n - 1)
                    return steps;
                
                auto& nextIndices = indicesOfValues[arr[i]];
                nextIndices.push_back(i - 1);
                nextIndices.push_back(i + 1);
                
                for(auto j : nextIndices) {
                    if(j > 0 && j < n && !vis.count(j)) {
                        q.push(j);
                        vis.insert(j);
                    }
                }
                nextIndices.clear();
            }
            steps++;
        }
        
        return 0;
    }
};