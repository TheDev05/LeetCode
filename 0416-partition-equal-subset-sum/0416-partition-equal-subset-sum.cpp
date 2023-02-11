class Solution {
public:

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int index)
{
    if(sum == 0) return 1;
    if (index >= num.size())
        return 0;

    if (storage[index][sum] == -1)
    {
        if (sum - num[index] >= 0 && getCount(num, storage, sum - num[index], index + 1))
            return 1;
        if (getCount(num, storage, sum, index + 1))
            return 1;

        storage[index][sum] = 0;
    }

    return storage[index][sum];
}

    bool canPartition(vector<int>& num) {
    int total = 0;
    for (auto i : num)
        total += i;

    if (total & 1)
        return 0;
    else
        total /= 2;

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(total + 1, -1));
    return getCount(num, storage, total, 0);
        
    }
};