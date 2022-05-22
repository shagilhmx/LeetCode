class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string numbers = countAndSay(n - 1);
        string ans;
        
        int i = 0;
        while(i < numbers.length()) {
            char each = numbers[i];
            int count = 0;
            while(i < numbers.length() && each == numbers[i]) {
                count++;
                i++;
            }
            
            ans += to_string(count);
            ans += each;
        }
        
        return ans;
    }
};