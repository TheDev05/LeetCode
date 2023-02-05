class Solution {
public:
    int coinChange(vector<int>& num, int k) {
    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(k + 1, 1e5));
    storage[storage.size() - 1][0] = 0;
    
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int k = 0; k < storage[0].size(); k++)
        {
            int val1 = 1e5, val2 = 1e5;
            if (k - num[i] >= 0)
                val1 = 1 + storage[i][k - num[i]];
            val2 = storage[i + 1][k];

            storage[i][k] = std::min(val1, val2);
        }
    }

    return (storage[0][k] == 1e5) ? -1 : storage[0][k]; 
    }
};