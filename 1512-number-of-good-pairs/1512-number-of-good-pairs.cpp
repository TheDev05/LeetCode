class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        std::map<int, int>data;
        for(auto i: nums)
            data[i]++;

        int sum = 0;
        for(auto i: data)
            sum += (i.second * (i.second - 1))/2;
        
        return sum;
    }
};