class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        
        //delete from front.
        int count = 0;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                count++;
                left++;
            }
            
            if(count > 1)
                break;
        }
        
        left = 0, right = s.length()-1;
        
        //delete from end.
        int count1 = 0;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                count1++;
                right--;
            }
            
            if(count1 > 1)
                break;
        }
        
        if(count == 1 || count1 == 1)
            return true;
        if(count == 0 || count1 == 0)
            return true;
        
        return false;
    }
};