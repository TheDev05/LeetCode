class SmallestInfiniteSet {
public:
    std::set<int>sub, add;
    
    SmallestInfiniteSet() {
        sub.insert(0);
    }
    
    int popSmallest() {
        
        int temp = 0;
        
        if(add.size())
        temp = *add.begin(),
        add.erase(add.begin());
        else temp = *sub.rbegin() + 1,
        sub.insert(temp);
        
        return temp;
    }
    
    void addBack(int num) {  
        if(sub.contains(num))
        add.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */