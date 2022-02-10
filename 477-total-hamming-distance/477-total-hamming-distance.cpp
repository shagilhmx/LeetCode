class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int>> hmap(32, vector<int>(2, 0));
        
        for(int i=0;i<32;++i) {
            for(int elem : nums) {
                auto temp = (elem & (1 << i));
                hmap[i][temp != 0]++;
            }
        }
        
        int sum = 0;
        for(auto elem : hmap) sum += elem[0] * elem[1];
        
        return sum;
    }
};