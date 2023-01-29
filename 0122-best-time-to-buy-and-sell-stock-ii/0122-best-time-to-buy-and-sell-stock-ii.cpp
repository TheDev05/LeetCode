class Solution {
public:
    
int getCount(std::vector<int> &num, std::vector<int> &storage, int buy, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index] == -1)
    {
        int val1 = 0, val2 = 0, val3 = 0;
        if (buy >= 0 && num[index] >= buy)
        {
            val1 = num[index] - buy;
        }

        val3 = getCount(num, storage, num[index], index + 1);
        val2 = getCount(num, storage, buy, index + 1);

        storage[index] = std::max(val1 + val3, val2);
    }

    return storage[index];
}
    
    int maxProfit(vector<int>& num) {
        
    std::vector<int> storage(num.size(), -1);
    return getCount(num, storage, -1, 0);

    }
};