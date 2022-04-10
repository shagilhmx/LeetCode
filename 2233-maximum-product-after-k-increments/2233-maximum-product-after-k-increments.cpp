class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int el : nums)
            pq.push(el);
        
        for(int i=1;i<=k;i++) {
            int front = pq.top();
            pq.pop();
            pq.push(front + 1);
        }
        
        long long ans = 1;
        while(!pq.empty()) {
            ans *= pq.top();
            ans %= (int)1e9 + 7;
            pq.pop();
        }
        
        return ans;
    }
};