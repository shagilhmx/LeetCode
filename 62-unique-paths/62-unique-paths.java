class Solution {
    public int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = Math.min(n, m) - 1;
        
        long res = 1;
        for(int i=1;i<=r;++i)
            res = res * (N--) / i;
        
        return (int)res;
    }
}