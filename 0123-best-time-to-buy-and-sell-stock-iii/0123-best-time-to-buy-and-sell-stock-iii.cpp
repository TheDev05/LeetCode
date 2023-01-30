class Solution {
public:
    
    int maxProfit(vector<int>& num) {
        
    std::vector<std::vector<std::vector<int>>> storage(num.size() + 1, std::vector<std::vector<int>>(2, std::vector<int>(3, 0)));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
                if (j)
                {
                    if (k > 0)
                        val1 = storage[i + 1][0][k - 1] - num[i];
                    val2 = storage[i + 1][j][k];
                }
                else
                {
                    val3 = num[i] + storage[i + 1][1][k];
                    val4 = storage[i + 1][j][k];
                }

                storage[i][j][k] = std::max({val1, val2, val3, val4});
            }
        }
    }

    return storage[0][1][2];

    }
};