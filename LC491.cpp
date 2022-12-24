#include <bits/stdc++.h>
using namespace std;

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
        if (i == 0 || num[i] >= temp.back())
        {
            temp.push_back(num[i]);
            fillStore(num, temp, store, i + 1);
            temp.pop_back();
        }
    }

    return 0;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    // for (auto i : num)
    //     std::cout << i << " ";

    std::vector<int> temp;
    std::vector<std::vector<int>> result;
    std::set<std::vector<int>> store;

    fillStore(num, temp, store, 0);

    for (auto i : store)
    {
        result.push_back(i);
    }
}