struct Node {
    Node* links[2];
    bool flag = false;
    
    bool containsKey(int k) {
        return links[k] != NULL;
    }
    
    Node* get(int k) {
        return links[k];
    }
    
    void put(int k, Node* node) {
        links[k] = node;
    }
};

class TireOperations {
    private: Node *root;
    public:
    TireOperations() {
        root = new Node();
    }
    
    public:
    void insert(int num) {
        Node *node = root;
        
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(!node -> containsKey(bit)) node -> put(bit, new Node());
            node = node -> get(bit);
        }
    }
    
    int findMax(int num) {
        Node *node = root;
        int maxNum = 0;
        
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(node -> containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node -> get(!bit);
            }
            else node = node -> get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        int maxXor = 0;
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int, pair<int, int>>> offlineQueries;
        
        for(int i=0;i<queries.size();i++) offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        
        sort(offlineQueries.begin(), offlineQueries.end());
        
        vector<int> ans(queries.size(), 0);
        
        int index = 0;
        
        TireOperations trie;
        
        for(int i=0;i<queries.size();i++) {
            int ai = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qIndex = offlineQueries[i].second.second;
            
            while(index < n && nums[index] <= ai) {
                trie.insert(nums[index]);
                index++;
            }
            if(index == 0) ans[qIndex] = -1;
            else ans[qIndex] = trie.findMax(xi);
        }
        return ans;
    }
};