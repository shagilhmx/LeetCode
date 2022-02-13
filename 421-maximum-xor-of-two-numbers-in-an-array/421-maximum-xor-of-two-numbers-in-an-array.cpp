struct Node {
    Node* links[2];
    bool flag = false;
    
    bool containsKey(int k) {
        return links[k] != nullptr;
    }
    
    Node* get(int k) {
        return links[k]; 
    }
    
    void put(int k, Node *node) {
        links[k] = node;
    }
    
};

class TrieOperations {
    private: Node *root;
    public:
    TrieOperations() {
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int maxXor = 0;
        
        TrieOperations trie;
        
        for(int i=0;i<n;i++) {
            trie.insert(nums[i]);
        }
        
        for(int i=0;i<n;i++) {
            maxXor = max(maxXor, trie.findMax(nums[i]));
        }
        
        return maxXor;
    }
};