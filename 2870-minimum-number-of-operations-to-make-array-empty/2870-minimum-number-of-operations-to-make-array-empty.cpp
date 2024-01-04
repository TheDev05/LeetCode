class Solution {
public:
    int minOperations(vector<int>& num) {
        
    std::map<int, int> data;
    for (auto i : num)
        data[i]++;

    int count = 0;
    for (auto i : data)
        if (i.second == 1)
            return -1;
        else
            count += ceil((double)i.second / 3);

    return count;   
        
    }
};