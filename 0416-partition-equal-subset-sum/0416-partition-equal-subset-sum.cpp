class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int total, int index)
{
    if (index >= num.size())
    {
        if (total - sum == sum)
            return true;
        return false;
    }

    if (storage[index][sum] == -1)
    {
        bool val1 = getCount(num, storage, sum + num[index], total, index + 1);
        bool val2 = getCount(num, storage, sum, total, index + 1);

        if (val1 || val2)
            storage[index][sum] = true;
        else
            storage[index][sum] = false;
    }

    return storage[index][sum];
}


    bool canPartition(vector<int>& num) {
        
    int total = accumulate(num.begin(), num.end(), 0);
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(total, -1));

    return getCount(num, storage, 0, total, 0);
        
    }
};