class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = -1, i;
        int leftArray[n], rightArray[n];
        stack<int> st;
        for (i = 0; i < n; i++) {
            if (st.empty()) {
                leftArray[i] = 0;
                st.push(i);
                continue;
            }
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    int curr = st.top();
                    st.pop();
                    int left = st.empty() ? 0 : st.top() + 1;
                    maxArea = max(maxArea, heights[curr] * (i - left));
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            int left = st.empty() ? 0 : st.top() + 1;
            maxArea = max(maxArea, heights[curr] * (i - left));
        }
        return maxArea;
    }
};