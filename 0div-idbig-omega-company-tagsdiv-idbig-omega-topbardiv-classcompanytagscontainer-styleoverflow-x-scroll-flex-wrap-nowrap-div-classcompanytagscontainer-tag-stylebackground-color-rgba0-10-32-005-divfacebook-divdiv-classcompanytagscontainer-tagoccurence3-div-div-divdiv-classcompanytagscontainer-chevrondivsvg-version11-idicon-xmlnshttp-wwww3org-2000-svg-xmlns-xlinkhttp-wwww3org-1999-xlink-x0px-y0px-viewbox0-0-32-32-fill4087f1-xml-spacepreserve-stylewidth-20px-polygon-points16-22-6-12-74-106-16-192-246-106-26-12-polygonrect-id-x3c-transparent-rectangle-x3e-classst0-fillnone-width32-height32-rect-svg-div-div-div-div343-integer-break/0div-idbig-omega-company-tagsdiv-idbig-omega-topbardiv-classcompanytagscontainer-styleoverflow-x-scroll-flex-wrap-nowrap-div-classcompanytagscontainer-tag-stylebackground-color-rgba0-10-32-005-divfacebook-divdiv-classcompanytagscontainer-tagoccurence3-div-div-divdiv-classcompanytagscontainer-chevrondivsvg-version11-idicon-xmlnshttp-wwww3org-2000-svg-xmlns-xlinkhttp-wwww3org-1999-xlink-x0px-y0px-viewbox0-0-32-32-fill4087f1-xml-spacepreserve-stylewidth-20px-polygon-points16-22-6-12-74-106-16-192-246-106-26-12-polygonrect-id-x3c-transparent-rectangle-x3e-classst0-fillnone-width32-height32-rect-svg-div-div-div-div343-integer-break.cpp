class Solution {
public:
int traverse(std::vector<std::vector<int>> &storage, int n, int index, int k)
{
    if (n == 0)
        return 1;

    if (index >= k)
        return 0;

    if (storage[index][n] == -1)
    {
        int val1 = 0, val2 = 0;
        if (n - index >= 0)
            val1 = index * traverse(storage, n - index, index, k);
        else
            return storage[index][n] = 0;

        val2 = traverse(storage, n, index + 1, k);

        storage[index][n] = std::max(val1, val2);
    }

    return storage[index][n];
}
    
    int integerBreak(int n) {
    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(n + 1, -1));
    return traverse(storage, n, 1, n);   
    }
};