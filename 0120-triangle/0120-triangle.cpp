class Solution {
public:
    int getCount(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int i, int j)
{
    if (i == num.size() - 1)
        return num[i][j];
    if (j > i)
        return INT_MAX;

    if (storage[i][j] == -1)
    {
        int down = getCount(num, storage, i + 1, j);
        int diagonal = getCount(num, storage, i + 1, j + 1);

        storage[i][j] = std::min(down, diagonal) + num[i][j];
    }

    return storage[i][j];
}

    int minimumTotal(vector<vector<int>>& num) {
        
    std::vector<std::vector<int>> storage;
    for (int i = 0; i < num.size(); i++)
    {
        std::vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++)
        {
            temp[j] = -1;
        }

        storage.push_back(temp);
    }

    return getCount(num, storage, 0, 0);
        
    }
};