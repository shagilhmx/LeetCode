class RandomizedCollection {
public:
    RandomizedCollection() {}
    ~RandomizedCollection() {}
    unordered_multimap<int, int> m;
    vector<unordered_multimap<int,int>::iterator> v;
    
    bool insert(int val) {
        bool b = !m.count(val);
        v.push_back(m.insert({val, v.size()}));
        return b;
    }
    
    bool remove(int val) {
        if (m.count(val)) {
            unordered_multimap<int,int>::iterator it = m.find(val);
            v.back()->second = it->second;
            swap(v[it->second], v.back());
            m.erase(it);
            v.pop_back();
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int var = rand() % v.size();
        return v[var]->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */