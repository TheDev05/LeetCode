class RandomizedSet {
public:
    std::set<int>num;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(num.contains(val)) return false;
        num.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(num.contains(val) == false) return false;
        num.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = num.begin();
        std::advance(it, (rand() % num.size()));
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