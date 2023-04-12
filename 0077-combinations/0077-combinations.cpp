class Solution {
public:
int traverse(std::vector<int> &num, std::vector<int> &temp, std::vector<std::vector<int>> &result, int target, int index)
{
    if (index >= num.size())
    {
        if (temp.size() == target)
            result.push_back(temp);

        return 0;
    }

    temp.push_back(num[index]);
    traverse(num, temp, result, target, index + 1);

    temp.pop_back();
    traverse(num, temp, result, target, index + 1);

    return 0;
}
    
    vector<vector<int>> combine(int n, int k) {
        
    std::vector<int> num(n);
    std::iota(num.begin(), num.end(), 1);

    std::vector<int> temp;
    std::vector<std::vector<int>> result;

    traverse(num, temp, result, k, 0);
    return result;
    }
};