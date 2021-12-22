class RandomizedSet {
public:
    unordered_set<int> uset;
    RandomizedSet() {}
    ~RandomizedSet() {}
    
    bool insert(int val) {
        int prevSize = uset.size();
        uset.insert(val);
        return uset.size() > prevSize;
    }
    
    bool remove(int val) {
        int prevSize = uset.size();
        uset.erase(val);
        return uset.size() < prevSize;
    }
    
    int getRandom() {
        int var = rand() % uset.size();
        unordered_set<int>::iterator it = uset.begin();
        for(int i=0;i<var;i++){
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */