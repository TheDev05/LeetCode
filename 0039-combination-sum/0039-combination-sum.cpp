class Solution {
public:
int traverse(std::vector<int> &num, std::vector<int> &temp, std::vector<std::vector<int>> &result, int target, int index)
{
    if (index >= num.size())
        return 0;

    if (target == 0)
    {
        result.push_back(temp);
        return 0;
    }

    if (target - num[index] >= 0)
    {
        temp.push_back(num[index]);
        traverse(num, temp, result, target - num[index], index);
        temp.pop_back();
    }

    traverse(num, temp, result, target, index + 1);
    return 0;
}
    
    vector<vector<int>> combinationSum(vector<int>& num, int k) {
        
    std::vector<int> temp;
    std::vector<std::vector<int>> result;

    traverse(num, temp, result, k, 0);
    return result;
    }
};