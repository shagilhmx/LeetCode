class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //using bfs
        
        unordered_set<string> words(wordList.begin(), wordList.end()), vis = { beginWord };
        
        if(words.find(endWord) == words.end()) return 0;
        
        queue<pair<string, int>> check;
        check.push({beginWord, 1}); // {word, steps to reach}.
        
        while(!check.empty()) {
            auto [ word, step ] = check.front();
            check.pop();
            
            if(word == endWord) return step;
            
            for(char &ch : word) {
                char prev = ch;
                for(char c='a';c<='z';c++) {
                    ch = c;
                    if(words.find(word) != words.end() && vis.find(word) == vis.end()) {
                        check.push({word, step + 1});
                        vis.insert(word);
                    } 
                }
                ch = prev;
            }
        }
        return 0;
    }
};