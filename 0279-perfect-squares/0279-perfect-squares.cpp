class Solution {
public:
    int numSquares(int n) {
    std::vector<int> num;
    for (int i = 1; i <= n; i++)
    {
        double val = sqrt(i);
        if (ceil(val) == floor(val))
            num.push_back(i);
    }

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(n + 1, 1e5));
    storage[storage.size() - 1][0] = 0;
    
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int count1 = 1e5, count2 = 1e5;
            if (j - num[i] >= 0)
                count1 = 1 + storage[i][j - num[i]];

            count2 = storage[i + 1][j];

            storage[i][j] = std::min(count1, count2);
        }
    }

    return storage[0][n];
    }
};