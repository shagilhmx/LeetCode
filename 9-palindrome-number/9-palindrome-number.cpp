class Solution {
public:
    bool isPalindrome(int x) {
        string rev="",temp;
        temp = to_string(x);
        int left = 0, right = temp.length()-1;
        
        while(left <= right) {
            if(temp[left++] != temp[right--])
                return false;
        }
        return true;
    }
};