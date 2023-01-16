class Solution {
public:
    int minPathSum(vector<vector<int>>& num) {
        
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));
    storage[num.size() - 1][num[0].size() - 1] = num[num.size() - 1][num[0].size() - 1];

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = num[0].size() - 1; j >= 0; j--)
        {
            if (i == num.size() - 1 && j == num[0].size() - 1)
                continue;
            int down = INT_MAX, right = INT_MAX;

            if (i != num.size() - 1)
                down = storage[i + 1][j];
            if (j != num[0].size() - 1)
                right = storage[i][j + 1];

            storage[i][j] = std::min(right, down) + num[i][j];
        }
    }

     return storage[0][0];
    }
};