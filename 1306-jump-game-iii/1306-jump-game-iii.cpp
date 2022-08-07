class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            if(arr[top] == 0)
                return true;
            
            if(arr[top] < 0)
                continue;
            
            if(top - arr[top] >= 0)
                q.push(top - arr[top]);
            
            if(top + arr[top] < arr.size())
                q.push(top + arr[top]);
            
            arr[top] *= -1;
        }
        
        return false;
    }
};