class Solution {
public:
    int trailingZeroes(int n) {
        int numberOfFives = 0;
        
        while(n >= 5){
            numberOfFives += floor(n/5);
            n = floor(n/5);
        }
        return numberOfFives;
    }
};