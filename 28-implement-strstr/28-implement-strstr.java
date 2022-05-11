class Solution {
    public int strStr(String haystack, String needle) {
        //brute
        int len = haystack.length();
        int j = 0;
        int i;
        for(i=0;i<len;i++)
        {
            if(haystack.charAt(i) == needle.charAt(j))
                j++;
            else
            {
                i = i - j; // return to index where we start matching.
                j = 0;
            }
            if(j == needle.length())
                return i -j + 1;
        }
        return -1;
    }
}