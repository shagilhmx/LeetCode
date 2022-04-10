class Solution {
public:
    string minimizeResult(string expression) {
        int divide = expression.find("+");
        
        string left = expression.substr(0, divide);
        string right = expression.substr(divide+1);
        
        int len1 = left.size(), len2 = right.size();
        string ans = "";
        int minAns = -1;
        
        for(int i=1;i<=len1;i++) {
            for(int j=1;j<=len2;j++) {
                string part1 = left.substr(0, len1 - i);
                string part2 = left.substr(len1 - i);
                string part3 = right.substr(0, j);
                string part4 = right.substr(j);
                
                int temp = stoi_(part1) * (stoi_(part2) + stoi_(part3)) * stoi_(part4);
                if(minAns == -1 || minAns > temp) {
                    minAns = temp;
                    ans = part1 + "(" + part2 + "+" + part3 + ")" + part4;
                }
            }
        }
        return ans;
    }
    
    int stoi_(string& s) {
        if(s == "")
            return 1;
        return stoi(s);
    }
};