class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num.size())
        return (k == 0) ? 0 : 1e7;

    if (storage[index][k] == -1)
    {
        int val1 = 1e7, val2 = 1e7;
        if (k - num[index] >= 0)
            val1 = 1 + getCount(num, storage, k - num[index], index);
        val2 = getCount(num, storage, k, index + 1);

        storage[index][k] = std::min(val1, val2);
    }

    return storage[index][k];
}

    
    
    int numSquares(int n) {
        
    std::vector<int> num;
    for (int i = 1; i <= n; i++)
    {
        double temp = sqrt(i);
        if (ceil(temp) == floor(temp))
            num.push_back(i);
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(n + 1, -1));
    return getCount(num, storage, n, 0);
        
    }
};