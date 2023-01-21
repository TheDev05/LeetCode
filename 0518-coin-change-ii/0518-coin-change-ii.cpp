class Solution {
public:

    int change(int k, vector<int>& num) {
    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(k + 1, 0));
    storage[storage.size() - 1][0] = 1;
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - num[i] >= 0)
                val1 = storage[i][j - num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 + val2;
        }
    }

      return storage[0][k];
    }
};