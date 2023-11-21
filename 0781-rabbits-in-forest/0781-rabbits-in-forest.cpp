class Solution {
public:
    int numRabbits(vector<int>& num) {
    std::map<int, int> data;
    for (auto i : num)
        data[i]++;

    int sum = 0;
    for (auto i : data)
    {
        if (i.second % (i.first + 1) == 0)
            sum += i.second;
        else
        {
            sum += i.second + (i.first + 1) - (i.second % (i.first + 1));
        }
    }

    return sum;
        
    }
};