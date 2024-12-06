class Solution {
public:
    int maxCount(vector<int>& num, int k, int max) {
    
    std::set<int> data;
    for (auto i : num)
        data.insert(i);

    int sum = 0, count = 0;
    for (int i = 1; i <= k; i++)
    {
        if (data.contains(i) == false && sum + i <= max)
        {
            sum += i;
            count++;
        }
    }

    return count; 

    }
};