class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        
        if(n % 2 == 0) return (1 + integerReplacement(floor(n/2)));
        return n == INT_MAX ? (integerReplacement(n - 1)) : (1 + min(integerReplacement(n - 1), integerReplacement(n + 1)));
    }
};