class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> files;
        vector<string> res;
        
        for(auto& name : names) {
            if(files.find(name) == files.end()) {
                files[name] = 1;
                res.push_back(name);
                continue;
            }
            
            string newName = name + '(' + to_string(files[name]++) + ')';
            while(files.find(newName) != files.end())
                newName = name + '(' + to_string(files[name]++) + ')';
            
            files[newName] = 1;
            res.push_back(newName);
        }
        return res;
    }
};