class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int index, int col)
{
    if (index >= num.size())
        return 0;

    if (storage[index][col] == -1)
    {
        int val1 = 0, val2 = 0;
        val1 = num[index][col] + traverse(num, storage, index + 1, col);
        val2 = num[index][col] + traverse(num, storage, index + 1, col + 1);

        storage[index][col] = min(val1, val2);
    }

    return storage[index][col];
}
    
    int minimumTotal(vector<vector<int>>& num) {
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[num.size() - 1].size(), -1));
    return traverse(num, storage, 0, 0);
        
    }
};