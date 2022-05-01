class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        for(int k=0;k<s.length();k++) {
            if(s[k] != '#')
                s[i++] = s[k];
            else if(i > 0) //backspace found remove a character.
                i--;
        }
        
        int j = 0;
        for(int k=0;k<t.length();k++) {
            if(t[k] != '#')
                t[j++] = t[k];
            else if(j > 0) //backspace found remove a character.
                j--;
        }
        
        if(i != j)
            return false;
        
        for(int k=0;k<i;k++) {
            if(s[k] != t[k]) //compare each character.
                return false;
        }
        
        return true;
    }
};