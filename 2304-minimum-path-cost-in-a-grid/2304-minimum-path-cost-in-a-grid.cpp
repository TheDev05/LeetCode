class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &cost, std::vector<std::vector<int>> &storage, int i, int j)
{
    if (i >= num.size())
        return 0;

    int min = INT_MAX;
    for (int col = 0; col < num[0].size(); col++)
    {
        if (i + 1 < num.size())
        {
            if (storage[i + 1][col] == -1)
                storage[i + 1][col] = traverse(num, cost, storage, i + 1, col);

            min = std::min(min, cost[num[i][j]][col] + storage[i + 1][col]);
        }
    }

    if (min == INT_MAX)
        min = 0;

    return min + num[i][j];
}
    
    int minPathCost(vector<vector<int>>& num, vector<vector<int>>& cost) {
        
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));
    int min = INT_MAX;

    for (int i = 0; i < num[0].size(); i++)
    {
        min = std::min(min, traverse(num, cost, storage, 0, i));
    }

    return min;        
    }
};