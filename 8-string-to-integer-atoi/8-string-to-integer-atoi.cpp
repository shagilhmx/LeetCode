class Solution {
public:
    int myAtoi(string s) {
        int i = 1,j=0;
        while(s[j] == ' '){
            j++;
        }
        if(s[j] == '-' | s[j] == '+'){
                if(s[j] == '-'){
                    i=-1;
                }
            j++;
            }
        long num=0,count=0;
        for(int y=j;y<s.length();y++){          
            if(std::isdigit(s[y]) == 1 ){ 
                num = 10*num + (s[y] - '0');
                if(num*i >= INT_MAX){
                   return INT_MAX;
               } 
                if(num*i <= INT_MIN){
                    return INT_MIN;   
                }  
            }else{
                break;
            }
        }
        num = i*num;
        return num;
    }
};