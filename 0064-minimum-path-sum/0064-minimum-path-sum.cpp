class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int row, int col)
{
    if (row == num.size() - 1 && col == num[0].size() - 1)
        return num[row][col];
    if (row >= num.size() || col >= num[0].size())
        return 1e5;

    if (storage[row][col] == -1)
    {
        int val1 = 1e5, val2 = 1e5;
        val1 = num[row][col] + traverse(num, storage, row + 1, col);
        val2 = num[row][col] + traverse(num, storage, row, col + 1);

        storage[row][col] = std::min(val1, val2);
    }

    return storage[row][col];
}
    
    int minPathSum(vector<vector<int>>& num) {
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));
    return traverse(num, storage, 0, 0);       
    }
};