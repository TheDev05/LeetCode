class Solution {
public:
    int findLongestChain(vector<vector<int>>& num) {
    std::sort(num.begin(), num.end());

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(num.size()+1, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j == 0 || num[j - 1][1] < num[i][0])
            val1 = 1 + storage[i + 1][i + 1];
            val2 = storage[i + 1][j];

            storage[i][j] = std::max(val1, val2);
        }
    }

    return storage[0][0];
    }
};