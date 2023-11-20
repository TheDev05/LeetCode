class Solution {
public:
    int reductionOperations(vector<int>& num) {
    std::map<int, int, greater<int>> data;
    for (auto i : num)
        data[i]++;

    int count = 0, temp = 0;
    while (data.size() > 1)
    {
        count += temp + data.begin()->second;
        temp += data.begin()->second;

        data.erase(data.begin());
    }

    return count;        
    }
};