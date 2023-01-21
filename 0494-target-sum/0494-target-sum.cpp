class Solution {
public:
    
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int index)
{
    if (index >= num.size())
        return (sum == 0) ? 1 : 0;

    if (storage[index][sum] == -1)
    {
        int val1 = 0, val2 = 0;
        if (sum - num[index] >= 0)
            val1 = getCount(num, storage, sum - num[index], index + 1);
        val2 = getCount(num, storage, sum, index + 1);

        storage[index][sum] = val1 + val2;
    }

    return storage[index][sum];
}

    
    int findTargetSumWays(vector<int>& num, int k) {
    int total = 0, sum = 0;
    for (auto i : num)
        total += i;
        
    if (k < -total || k > total)
        return 0;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }else return 0;

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(sum + 1, -1));
    return getCount(num, storage, sum, 0); 
        
    }
};