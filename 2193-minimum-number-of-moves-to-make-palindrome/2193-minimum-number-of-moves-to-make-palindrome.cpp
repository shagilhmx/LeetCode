class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0, left = 0, right = s.size()-1;
        
        /*we take the first half as the main part and compare the second half with it,
        if 1st half(x) == 2nd half(x) then its ok, otherwise decrement right--, to 
        get when 1st half(x) == 2nd half(x)*/
        while(left < right) {
            int l = left, r = right;
            while(s[l] != s[r]) r--;
            
            if(l == r) {
                swap(s[r], s[r + 1]);
                res++;
                continue;
            }
            else {
                while(r < right) {
                    swap(s[r], s[r + 1]);
                    res++; 
                    r++;
                }
            }
            left++;
            right--;
        }
        return res;
    }
};