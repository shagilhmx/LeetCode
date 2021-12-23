class MyHashSet {
public:
    MyHashSet() {}
    ~MyHashSet() {}
    
    void add(int key) {
        if(!contains(key))
            hashSet[hash(key)].push_back(key);
    }
    
    void remove(int key) {
        auto pos = find(hashSet[hash(key)].begin(), hashSet[hash(key)].end(), key);
        if(pos != hashSet[hash(key)].end())
            hashSet[hash(key)].erase(pos);
    }
    
    bool contains(int key) {
        auto pos = find(hashSet[hash(key)].begin(), hashSet[hash(key)].end(), key);
        if(pos != hashSet[hash(key)].end())
            return true;
        return false;
    }
    private:
        vector<int> hashSet[50];
    
    int hash(int key){
        return key % 50;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */