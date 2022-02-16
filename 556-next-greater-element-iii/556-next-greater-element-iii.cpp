class Solution {
public:
    int nextGreaterElement(int n) {
        int i, k;
        string s = to_string(n);
        
        int size = s.length();
        
        for(i=size-2;i>=0;i--) if(s[i] < s[i+1]) break;
        
        if(i < 0) reverse(s.begin(), s.end()); //no break point just reverse otherwise travrse from back s[k] > s[i] then break
        else {
            for(k=size-1;k>i;k--) if(s[k] > s[i]) break;
        
            swap(s[i], s[k]);
            reverse(s.begin() + i + 1, s.end());
        }
        
        if(s.size() < 2 || s == to_string(n)) return -1;
        
        long long ans = stoll(s);
        if(ans < n) return -1;
        
        return ans > INT_MAX ? -1 : ans;
    }
};