class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int total, int index)
{
    if (index >= num.size())
        return (sum == (total - sum) ? 1 : 0);

    if (storage[index][sum] == -1)
    {
        if (getCount(num, storage, sum + num[index], total, index + 1))
            return 1;
        if (getCount(num, storage, sum, total, index + 1))
            return 1;

        storage[index][sum] = 0;
    }

    return storage[index][sum];
}

    
    bool canPartition(vector<int>& num) {
    int total = 0;
    for (auto i : num)
        total += i;

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(total + 1, -1));
    return getCount(num, storage, 0, total, 0);
        
    }
};