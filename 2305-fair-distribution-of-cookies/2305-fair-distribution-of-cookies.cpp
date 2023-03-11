class Solution {
public:

int mini = INT_MAX;
int getCount(std::vector<int> &num, std::vector<int> &temp, int tempSum, int index, int k, int sum)
{
    if (temp.size() == k - 1 && tempSum != sum)
    {
        int local = sum - tempSum;
        temp.push_back(local);

        // std::cout << tempSum << '\n';

        int max = INT_MIN;
        for (auto i : temp)
            max = std::max(max, (int)i);

        mini = std::min(mini, max);
        temp.pop_back();
        return 0;
    }

    // for (auto i : temp)
    //     std::cout << i << " ";
    // std::cout << '\n';

    int val = 0;
    for (int i = index; i < num.size(); i++)
    {
        val += num[i];
        tempSum += num[i];

        // std::cout << val << '\n';

        temp.push_back(val);
        getCount(num, temp, tempSum, i + 1, k, sum);
        temp.pop_back();
    }

    return 0;
}

    int getSubs(std::vector<int> &num, std::vector<std::vector<int>> &store, std::vector<int> &temp, std::set<int> &inox, int k, int sum)
{
    if (temp.size() == num.size())
    {
        store.push_back(temp);
        return 0;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (inox.count(i) == false)
        {
            inox.insert(i);
            temp.push_back(num[i]);

            getSubs(num, store, temp, inox, k, sum);

            inox.erase(i);
            temp.pop_back();
        }
    }

    return 0;
}

    int distributeCookies(vector<int>& cookies, int k) {
    int sum = accumulate(cookies.begin(), cookies.end(), 0);

    std::set<int> inox;
    std::vector<int> temp;
    std::vector<std::vector<int>> store;

    getSubs(cookies, store, temp, inox, k, sum);
    temp.clear();

    for (auto i : store)
    {
        getCount(i, temp, 0, 0, k, sum);
    }

    return mini;

    }
};