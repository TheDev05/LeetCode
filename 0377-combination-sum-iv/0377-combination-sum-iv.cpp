class Solution {
public:
int traverse(std::vector<int> &num, std::vector<std::vector<int>> &storage, int target)
{
    if (target == 0)
        return 1;

    if (target < 0)
        return 0;

    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (storage[i][target] == -1)
            storage[i][target] = traverse(num, storage, target - num[i]);

        count += storage[i][target];
    }

    return count;
}

    int combinationSum4(vector<int>& num, int target) {

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(target + 1, -1));
    return traverse(num, storage, target);       
    }
};