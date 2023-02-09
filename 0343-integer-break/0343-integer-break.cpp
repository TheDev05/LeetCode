class Solution {
public:
int getCount(std::vector<std::vector<int>> &storage, int n, int k, int index)
{
    if (n == 0 || index >= k)
        return 1;

    if (storage[index][n] == -1)
    {
        int val1 = 0, val2 = 0;
        if (n - index >= 0)
            val1 = index * getCount(storage, n - index, k, index);
        val2 = getCount(storage, n, k, index + 1);

        storage[index][n] = std::max(val1, val2);
    }

    return storage[index][n];
}

    int integerBreak(int n) {
    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(n + 1, -1));
    return getCount(storage, n, n, 1);
        
    }
};