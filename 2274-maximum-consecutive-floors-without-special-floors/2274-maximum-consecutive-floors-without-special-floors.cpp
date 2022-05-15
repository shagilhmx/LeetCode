class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0, n = special.size();
        sort(special.begin(), special.end());
        
        ans = max(ans, top - special[n - 1]);
        ans = max(ans, special[0] - bottom);
        
        for(int i=1;i<n;i++)
            ans = max(ans, special[i] - special[i - 1] - 1);
        
        return ans;

    }
};

/*
INTUITION : 
	1. we are given a range from top to bottom in which we have to make cuts (special vector) )and
	 return the interval with maximum number of elements.
	2. since the cuts are to be made in sorted order so first of all sort the vector.
	3. handle the first cut and the last cut  and store the maximum result in a variable.
	4. simply loop through special array to count no. of elements in between the cuts. 
*/