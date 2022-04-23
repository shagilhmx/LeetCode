class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        
        for(int el : asteroids) {
            if(el > 0)
                st.push(el);
            else {
                //in case of smaller next element.
                while(!st.empty() && st.top() > 0 && st.top() < abs(el))
                    st.pop();
                //in case of equal elements
                if(!st.empty() && st.top() == abs(el))
                    st.pop();
                //incase of greater than element
                else if(!st.empty() && st.top() > abs(el))
                    continue;
                //otherwise
                else st.push(el);
            }
        }
        
        int m = st.size();
        vector<int> ans(m);
        int i = m - 1;
        while(!st.empty()) {
            ans[i--] = (st.top());
            st.pop();
        }
        
        return ans;
    }
};