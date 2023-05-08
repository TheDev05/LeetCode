class Solution {
public:

    std::vector<std::vector<int>> getSub(std::vector<int> &num, set<int> &inox, std::vector<int> &temp, std::vector<std::vector<int>> &result, int index)
{
    for (int i = 0; i < num.size(); i++)
    {
        if (inox.count(num[i]) == false)
        {
            inox.insert(num[i]);
            temp.push_back(num[i]);

            getSub(num, inox, temp, result, i);

            temp.pop_back();
            inox.erase(num[i]);
        }
    }

    if (temp.size() == num.size())
    {
        result.push_back(temp);
    }

    return result;
}
    vector<vector<int>> permute(vector<int>& nums) {
    set<int> inox;
    std::vector<int>temp;
    std::vector<std::vector<int>> result;

    getSub(nums, inox, temp, result, 0);
    return(result);
    }
};