class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
            
        int i = 0,j = 0;
        
        int number1 = 0, number2 = 0;
        
        while(i < n1 || j < n2) {
            
            //generating number.
            while(i < n1 && version1[i] != '.') {
                number1 = number1 * 10 + (version1[i] - '0');
                i++;
            }
            
            //generating number.
            while(j < n2 && version2[j] != '.') {
                number2 = number2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if(number1 > number2) return 1;
            if(number1 < number2) return -1;
            
            //if equal then we will generate the numbers again.
            number1 = 0, number2 = 0;
            
            //move the pointers.
            i++;
            j++;
        }
        return 0;
    }
};