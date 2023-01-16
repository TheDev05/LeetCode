class Solution {
public:
    int minimumTotal(vector<vector<int>>& num) {
        
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num.size(), -1));
    for (int i = 0; i < storage[storage.size() - 1].size(); i++)
    {
        storage[storage.size() - 1][i] = num[num.size() - 1][i];
    }

    for (int i = num.size() - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = storage[i + 1][j];
            int diagonal = storage[i + 1][j + 1];

            storage[i][j] = std::min(down, diagonal) + num[i][j];
        }
    }

    return storage[0][0];
        
    }
};