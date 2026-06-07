class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
       std::map<int, int>data;
       std::vector<int>result;

       for(auto i: nums){
            if (data.count(i))
                result.push_back(i);
            data[i]++;
    }

        return result; 
    }
};