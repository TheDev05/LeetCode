class Solution {
public:
    int coinChange(vector<int>& num, int k) {
        
    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(k + 1, 1e8));
    storage[storage.size() - 1][0] = 0;
    
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 1e8, val2 = 1e8;
            if (j - num[i] >= 0)
                val1 = 1 + storage[i][j - num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = std::min(val1, val2);
        }
    }

    int res = storage[0][k];
    if(res==1e8)res=-1;
        
    return res;
        
    }
};