class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int temp, int sum, int k, int index)
{
    if (index >= num.size())
        return ((sum - temp) - temp == k) ? 1 : 0;

    if (storage[index][temp] == -1)
    {
        int val1 = 0, val2 = 0;

        val1 = getCount(num, storage, temp + num[index], sum, k, index + 1);
        val2 = getCount(num, storage, temp, sum, k, index + 1);

        storage[index][temp] = (val1 + val2);
    }

    return storage[index][temp];
}
    
    int findTargetSumWays(vector<int>& num, int k) {
    int sum = 0;
    for (auto i : num)
        sum += i;

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(sum + 1, -1));
    return getCount(num, storage, 0, sum, k, 0);
        
    }
};