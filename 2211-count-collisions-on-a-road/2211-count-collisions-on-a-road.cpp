class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length(), ans = 0;
        
        /*
        1. For all 'R' check the next index, if u get collision change current index and    
           next index to 'S'.
        2. For all 'L' check the previous index, if u get collision change the current index
           and pervious index to 'S'.
        3. For all 'S' skip it.
        4. whenever you change current index to 'S', look backward for all continous                    occurance of R.
        */
        
        for(int i=0;i<n;i++) {
            if(directions[i] == 'S') continue;
            
            if(i + 1 < directions.size() && directions[i] == 'R' && directions[i + 1] != 'R') {
                if(directions[i + 1] == 'L') {
                    directions[i + 1] = 'S';
                    ans++;
                }
                directions[i] = 'S';
                ans++;
            }
            
            if(i - 1 >= 0 && directions[i] == 'L' && directions[i - 1] != 'L') {
                if(directions[i - 1] == 'R') {
                    directions[i - 1] = 'S';
                    ans++;
                }
                directions[i] = 'S';
                ans++;
            }
            
            if(directions[i] == 'S') {
                int j = i - 1;
                while(j >= 0 && directions[j] == 'R') {
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }
};