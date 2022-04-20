class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        vector<long long> ans;
        
        int defaultLength = (intLength + 1) / 2;
        
        int lowerBound = (long)pow(10, defaultLength - 1);
        int upperBound = (long)pow(10, defaultLength) - 1;
        
        for(int q : queries) {
            int totalCount = (upperBound - lowerBound) + 1;
            
            if(q <= totalCount) {
                string leftHalf = to_string(lowerBound + q - 1);
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                
                long res = stol(leftHalf + rightHalf.substr(intLength % 2));
                ans.push_back(res);
            }
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};

/*
we divide the len in to half, like if len = 4, then we use 10 - 99
10 - 01
11 - 11
12 - 21

we take lowerbound and upperbound as limit.
after which we there is no palindrome.

left half is lowerbound + queries[i] - 1.
right half is reverse of leftbound

add lefthalf + righthalf(intLength % 2).
as we will have to remove odd number of zeros.

if its out of range then add -1.
*/