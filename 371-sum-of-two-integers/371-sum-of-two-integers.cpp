class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned carry=a&b;
            a=a^b;
            b=carry<<1;
        }
        return a;
    }
};

/*
1 -> 0001           2 -> 0010 
2 -> 0010           3 -> 0011
_________           _________
3 -> 0011           5 -> 0101
*/