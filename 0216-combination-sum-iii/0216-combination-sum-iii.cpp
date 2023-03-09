class Solution {
public:
    int fillStore(std::vector<int> &num, std::vector<int> &temp, std::vector<std::vector<int>> &store, int k, int targetSum, int index, int sum)
{
    if (temp.size() == k && sum == targetSum)
    {
        store.push_back(temp);
        return 0;
    }

    if (index >= num.size())
        return 0;

    for (int i = index; i < num.size(); i++)
    {
        temp.push_back(num[i]);
        sum += num[i];

        fillStore(num, temp, store, k, targetSum, i + 1, sum);

        sum -= num[i];
        temp.pop_back();
    }

    return 0;
}
    vector<vector<int>> combinationSum3(int k, int n) {
    std::vector<int> num(9), temp;
    std::iota(num.begin(), num.end(), 1);

    std::vector<std::vector<int>> store;
    fillStore(num, temp, store, k, n, 0, 0);

    return store;
    }
};