class Solution {
    bool possible(long long mid, vector<int>& quantities, int n) {
        long long countNoOfshops = 0; //counting the number of shops.
        for(int el : quantities) {
            countNoOfshops += el / mid; //count of number of shop to which we can distribute our product.
            if(el % mid != 0) //if we have left with some extra product which is lesser than last ones.
                countNoOfshops++;
        }
        
        return countNoOfshops <= n ? 1 : 0; //if count of shops is less than given number of shops.
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum = 0;
        for(int el : quantities)
            sum += el;
        
        long long left = 0, right = sum;
        long long ans = sum;
        while(left <= right) {
            long long mid = (right + left) / 2;
            
            if(mid == 0)
                break;
            
            if(possible(mid, quantities, n)) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
};