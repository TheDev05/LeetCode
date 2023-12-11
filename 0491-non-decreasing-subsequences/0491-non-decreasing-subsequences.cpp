class Solution {
public:

int fillStore(std::vector<int> &num, std::vector<int> &temp, std::set<std::vector<int>> &store, int index)
{
    if (temp.size() >= 2)
        store.insert(temp);

    if (index >= num.size())
    {
        return 0;
    }

    for (int i = index; i < num.size(); i++)
    {
        if (temp.size() == 0 || num[i] >= temp.back())
        {
            temp.push_back(num[i]);
            fillStore(num, temp, store, i + 1);
            temp.pop_back();
        }
    }

    return 0;
}


    vector<vector<int>> findSubsequences(vector<int>& nums) {

    std::vector<int> temp;
    std::vector<std::vector<int>> result;
    std::set<std::vector<int>> store;

    fillStore(nums, temp, store, 0);

    for (auto i : store)
    {
        result.push_back(i);
    }  

    return result;

    }
};