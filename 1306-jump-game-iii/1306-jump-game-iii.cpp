class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        set<int> vis;
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            if(arr[top] == 0)
                return true;
            
            if(vis.count(top))
                continue;
            
            vis.insert(top);
            
            if(top - arr[top] >= 0)
                q.push(top - arr[top]);
            
            if(top + arr[top] < arr.size())
                q.push(top + arr[top]);
        }
        
        return false;
    }
};