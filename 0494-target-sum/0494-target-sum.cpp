class Solution {
public:
int getCount(std::vector<int> &num, std::map<std::pair<int, int>, int> &storage, int k, int index)
{
    if (index >= num.size())
        return (k == 0) ? 1 : 0;

    if (storage.count({index, k}) == false)
    {
        int val1 = 0, val2 = 0;
        val1 = getCount(num, storage, k + num[index], index + 1);
        val2 = getCount(num, storage, k - num[index], index + 1);

        storage[{index, k}] = (val1 + val2);
    }

    return storage[{index, k}];
}
    
    int findTargetSumWays(vector<int>& num, int k) {
    std::map<std::pair<int, int>, int> storage;
    return getCount(num, storage, k, 0);
        
    }
};