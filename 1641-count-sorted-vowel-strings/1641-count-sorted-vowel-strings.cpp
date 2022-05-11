class Solution {
public:
    int countVowelStrings(int n) {
        string vowels = "aeiou";
        return helper(vowels, 0, n);
    }
    
    int helper(string vowels, int index, int end) {
        if(end == 0) //a string of length n is formed.
            return 1;
        
        if(index == vowels.size()) //if vowels are exausted.
            return 0;
        
        int pick = helper(vowels, index, end - 1);
        int notPick = helper(vowels, index + 1, end);
        
        return pick + notPick;
    }
};