class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        long firstStringSum = 0, secondStringSum = 0;
        
        for(int i=0;i<s.length();i++) firstStringSum += (i + 1) * int(s[i] - 'a' + 1);
        
        for(int i=0;i<t.length();i++) secondStringSum += (i + 1) * int(t[i] - 'a' + 1);
        
        if(firstStringSum == secondStringSum) return true;
        
        return false;
    }
};