class Solution {
public:
       
    int findTargetSumWays(vector<int>& num, int k) {
    int total = 0, sum = 0;
    for (auto i : num)
        total += i;
        
    if (k < -total || k > total)
        return 0;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }else return 0;

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(sum + 1, 0));
    storage[storage.size() - 1][0] = 1;
    
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - num[i] >= 0)
                val1 = storage[i + 1][j - num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 + val2;
        }
    }

    return storage[0][sum]; 
        
    }
};