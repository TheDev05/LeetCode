class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int k, int index)
{
    if (index >= num.size())
    {
        if (k == sum)
            return true;
        return false;
    }

    if (storage[index][sum] == -1)
    {
        bool val1 = false;
        if(sum + num[index] <= k)
            val1 = getCount(num, storage, sum + num[index], k, index + 1);
        bool val2 = getCount(num, storage, sum, k, index + 1);
        
        storage[index][sum] = val1 | val2;
    }

    return storage[index][sum];
}

    bool canPartition(vector<int>& num) {
        
    int k = accumulate(num.begin(), num.end(), 0);
    if(k & 1) return false;
    else k = k / 2;
        
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(k+1, -1));

    return getCount(num, storage, 0, k, 0);
        
    }
};