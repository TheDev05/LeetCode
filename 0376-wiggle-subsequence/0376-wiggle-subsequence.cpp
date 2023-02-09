class Solution {
public:
   
    int wiggleMaxLength(vector<int>& num) {
        
    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(2, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            int val = 0;
            for (int k = i + 1; k < num.size(); k++)
            {
                int ok = 0;
                if (num[k] - num[i] > 0)
                    ok = 1;
                else if (num[k] - num[i] < 0)
                    ok = 0;
                else
                    continue;

                if (i == 0 || j != ok)
                    val = std::max(val, storage[k][ok]);
            }

            storage[i][j] = 1 + val;
        }
    }

    return storage[0][1];
        
    }
};