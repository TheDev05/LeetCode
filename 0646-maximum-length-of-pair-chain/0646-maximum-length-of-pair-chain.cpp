class Solution {
public:
int getCount(std::vector<std::pair<int, int>> &num, std::vector<std::vector<int>> &storage, int prevIndex, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][prevIndex] == -1)
    {
        int val1 = 0, val2 = 0;
        if (prevIndex == 0 || num[prevIndex - 1].second < num[index].first)
            val1 = 1 + getCount(num, storage, index + 1, index + 1);
        val2 = getCount(num, storage, prevIndex, index + 1);

        storage[index][prevIndex] = std::max(val1, val2);
    }

    return storage[index][prevIndex];
}
    
    int findLongestChain(vector<vector<int>>& temp) {
        
    std::vector<std::pair<int, int>> num(temp.size());
    for (int i = 0; i < temp.size(); i++)
    {
        num[i].first = temp[i][0];
        num[i].second = temp[i][1];
    }
        
    std::sort(num.begin(), num.end());

    std::vector<std::vector<int>>storage(num.size(), std::vector<int>(num.size(), -1));
    return getCount(num, storage, 0, 0);      
    }
};