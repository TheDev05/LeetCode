class Solution {
public:
    
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num.size())
        return (k == 0) ? 1 : 0;

    if (storage[index][k] == -1)
    {
        int val1 = 0, val2 = 0;
        if (k - num[index] >= 0)
            val1 = getCount(num, storage, k - num[index], index);
        val2 = getCount(num, storage, k, index + 1);

        storage[index][k] = val1 + val2;
    }

    return storage[index][k];
}

    int change(int k, vector<int>& num) {
       std::vector<std::vector<int>> storage(num.size(), std::vector<int>(k + 1, -1));
    return getCount(num, storage, k, 0);
    }
};