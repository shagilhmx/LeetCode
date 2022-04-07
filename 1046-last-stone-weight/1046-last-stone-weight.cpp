class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int el : stones)
            pq.push(el);
        
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if(first == second)
                pq.push(0);
            if(first != second)
                pq.push(first - second);
        }
        
        int res = pq.top();
        return res;
    }
};