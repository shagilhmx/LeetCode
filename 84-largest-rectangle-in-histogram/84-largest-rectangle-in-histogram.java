class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int[] leftSmaller = new int[n];
        int[] rightSmaller = new int[n];
        
        for(int i=0;i<n;i++) {
            while(!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
            
            if(st.isEmpty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.peek() + 1;
            st.push(i);
        }
        
        //clear the stack.
        while(!st.isEmpty()) st.pop();
        
        for(int i=n-1;i>=0;i--) {
            while(!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
            
            if(st.isEmpty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.peek() - 1;
            st.push(i);
        }
        
        int maxA = 0;
        for(int i=0;i<n;i++)
            maxA = Math.max(maxA, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        
        return maxA;
    }
}