class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        
        std::map<int, int>data;
        for(auto i: friends)
            data[i]++;

        std::vector<int>result;
        for(auto i: order)
            if(data.count(i)) result.push_back(i);

        return result;

    }
};