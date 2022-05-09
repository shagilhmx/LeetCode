class Solution {
    public int numDistinct(String s, String t) {
        int n=s.length();
        int m=t.length();
        
        int[] curr = new int[m + 1];
        
        curr[0]=1;
        
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                if(s.charAt(i-1) == t.charAt(j-1)) curr[j] = curr[j-1] + curr[j];
        
        return (int)curr[m];
    }
}