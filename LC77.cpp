#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<int> &num, std::vector<std::vector<int>> &store, std::vector<int> &temp, int k, int index)
{
    if (temp.size() == k)
    {
        store.push_back(temp);
        return 0;
    }

    if (index >= num.size())
        return 0;

    for (int i = index; i < num.size(); i++)
    {
        temp.push_back(num[i]);
        fillStore(num, store, temp, k, i + 1);
        temp.pop_back();
    }

    return 0;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n), temp;
    for (int i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }

    std::vector<std::vector<int>> store;
    fillStore(num, store, temp, k, 0);

    for (auto i : store)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}