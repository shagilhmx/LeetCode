class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        int n = arr.size();
        
        long res = 0;
        for(int i=0;i<n;i++) {
            vector<int> mpp(101, 0);
            for(int j=i+1;j<n;j++) {
                int k = target - arr[i] - arr[j];
                
                if(k >= 0 && k <= 100 && mpp[k] > 0) {
                    res += mpp[k];
                    res %= mod;
                }
                mpp[arr[j]]++;
            }
        }
        return res;
    }
};