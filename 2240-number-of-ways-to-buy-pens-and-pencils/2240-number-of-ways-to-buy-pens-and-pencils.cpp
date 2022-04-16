class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ans = 0, x;
        
        for(x = 0; ;x++) {
            int val = total - (cost1 * x);
            
            if(val < 0)
                break;
            
            ans += (long)floor((long)val /(long)cost2) + 1;
        }
        
        if(ans == 0)
            return 1;
        return ans;
    }
};

/*
think it in this way, total = cost1 * quantity1 + cost2 * quantity2;
*/