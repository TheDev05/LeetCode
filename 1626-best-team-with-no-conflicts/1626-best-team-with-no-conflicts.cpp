class Solution {
public:
    int getCount(std::vector<std::pair<int, int>> &num, std::vector<std::vector<int>> &storage, int temp, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][temp] == -1)
    {
        int val1 = 0, val2 = 0;
        if (temp == 0 || num[index].second >= num[temp - 1].second)
            val1 = num[index].second + getCount(num, storage, index + 1, index + 1);
        val2 = getCount(num, storage, temp, index + 1);

        storage[index][temp] = std::max(val1, val2);
    }

    return storage[index][temp];
}

    
    int bestTeamScore(vector<int>& num1, vector<int>& num2) {
    std::vector<std::pair<int, int>> num;
    for (int i = 0; i < num1.size(); i++)
    {
        num.push_back({num2[i], num1[i]});
    }

    sort(num.begin(), num.end());

    std::vector<std::vector<int>> storage(num.size(),       std::vector<int>(num.size(), -1));
    return getCount(num, storage, 0, 0);
        
    }
};