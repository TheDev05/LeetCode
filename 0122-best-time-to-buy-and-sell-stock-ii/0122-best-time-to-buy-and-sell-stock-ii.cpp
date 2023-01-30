class Solution {
public:
    
    int maxProfit(vector<int>& num) {
        
    std::vector<int> prev(2, 0);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
            if (j)
            {
                val1 = prev[0] - num[i];
                val2 = prev[j];
            }
            else
            {
                val3 = num[i] + prev[1];
                val4 = prev[j];
            }

            prev[j] = std::max({val1, val2, val3, val4});
        }
    }

    return prev[1];
        
    }
};