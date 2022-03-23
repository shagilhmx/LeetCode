class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double totalSum = 0;
        double requiredSum = 0;
        
        for(int x : nums) {
            totalSum += x;
            pq.push(x);
        }
        
        requiredSum = totalSum / 2;
        int minOperations = 0;
        
        while(totalSum > requiredSum) {
            double curr = pq.top();
            pq.pop();
            curr = curr / 2;
            totalSum -= curr;
            pq.push(curr);
            minOperations++;
        }
        return minOperations;
    }
};