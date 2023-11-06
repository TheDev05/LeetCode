class SeatManager {
public:
    std::set<int>num;
    SeatManager(int n) {
        for(int i =0;i<n;i++) num.insert(i+1);
    }
    
    int reserve() {
        int temp = *num.begin();
        num.erase(num.begin());
        return temp;
    }
    
    void unreserve(int seatNumber) {
        num.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */