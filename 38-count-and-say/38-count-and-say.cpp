class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1"; //base case.
        
        string numbers = countAndSay(n-1);
        //say the number.
        int i=0;
        string tempStore = "";
        while(i < numbers.length()) {
            int count = 0;
            int each = numbers[i];
            while(i < numbers.length() && numbers[i] == each) {
                count++;
                i++;
            }
            tempStore += to_string(count);
            tempStore += each;
        }
        
        return tempStore;
    }
};