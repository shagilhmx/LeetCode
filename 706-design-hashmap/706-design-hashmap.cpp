class MyHashMap {
private: int hmap[1000001];
public:
    MyHashMap() {
        memset(hmap, -1, sizeof(hmap));
    }
    
    void put(int key, int value) {
        remove(key);
        hmap[key]= value;
    }
    
    int get(int key) {
        return hmap[key];
    }
    
    void remove(int key) {
        hmap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */