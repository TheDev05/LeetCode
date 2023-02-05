class Solution {
public:
    int maxProfit(vector<int>& num) {
    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(2, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            if (j)
            {
                int val1 = 0, val2 = 0;
                val1 = storage[i + 1][0] - num[i];
                val2 = storage[i + 1][j];

                storage[i][j] = std::max(val1, val2);
            }
            else
            {
                int val1 = num[i], val2 = 0;
                if (i + 2 < storage.size())
                    val1 += storage[i + 2][1];
                val2 = storage[i + 1][j];

                storage[i][j] = std::max(val1, val2);
            }
        }
    }

    return storage[0][1];
        
    }
};