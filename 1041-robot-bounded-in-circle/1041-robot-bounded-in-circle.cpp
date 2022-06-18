class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> end;
        end = {0, 0};
        char currDir = 'N';
        
        for(auto each : instructions) {
            switch(each) {
                case 'G':
                    switch(currDir) {
                        case 'N':
                            end.second++;
                            break;
                        case 'S':
                            end.second--;
                            break;
                        case 'E':
                            end.first++;
                            break;
                        case 'W':
                            end.first--;
                            break;
                    }
                    break;
                case 'L':
                  switch(currDir) {
                        case 'N':
                            currDir = 'W';
                            break;
                        case 'S':
                            currDir = 'E';
                            break;
                        case 'E':
                            currDir = 'N';
                            break;
                        case 'W':
                            currDir = 'S';
                            break;
                    }
                    break;  
                case 'R':
                  switch(currDir) {
                        case 'N':
                            currDir = 'E';
                            break;
                        case 'S':
                            currDir = 'W';
                            break;
                        case 'E':
                            currDir = 'S';
                            break;
                        case 'W':
                            currDir = 'N';
                            break;
                    }
                    break;
            }
        }
        
        return ((end.first == 0 && end.second == 0) || currDir != 'N') ? true : false;
    }
};