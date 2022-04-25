class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        unordered_map<int, vector<int>> mpp;
        //map heights -> length of that heights.
        
        for(int i=0;i<rectangles.size();i++)
            mpp[rectangles[i][1]].push_back(rectangles[i][0]);
        
        //sort to apply binary search.
        for(int i=0;i<=100;i++)
            sort(mpp[i].begin(), mpp[i].end());
        
        vector<int> ans;
        
        // binary search return the idx in array from which the values are >= x
		// the values at this and right of this are the lengths possible
		// so substract by size of array to get the number
        for(auto p : points) {
            int cnt = 0;
            for(int i=p[1];i<=100;i++) {
                if(mpp.find(i) != mpp.end()) {
                    cnt += mpp[i].size() - binarySearch(mpp[i], p[0]);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    int binarySearch(vector<int>& arr,int& x) {
        int left = 0, right = arr.size()-1;
        int ans = arr.size();
        
        // if we find no m such that arr[m]>=x, means that our x is greater than all values             of length, in such case we return idx n (i.e. size of arr)
		// reason being, we substract our idx by size of arr to get number of rectangles                greater than that in main fxn, so return arr.size would give us 0 (which we                want)
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] >= x) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};

/*
This tells us that we cannot go through all the rectangles for all the points, coz that will be 5 * 10^4 * 5* 10^4 which would be > 10^8 operations, so would give TLE.

This gives intution of doing something like binary search.
But how do we do that?

We see that heights are only from 0 to 100. So can traverse in them. But lengths can be till 10^9 so have to do binary search in that.

So, we create an unordered_map which maps each height to lengths of rectangles having that height.

Then we sort all those length vectors (since we have to apply binary search)

We make a helper function for binary search which gives the idx of the first position with value greater than or equal to given x.

Now just binary search for all the heights from 0 to 100 and get how many lengths are greater than the x cordinate of the point. The sum of all of these is our answer.
*/