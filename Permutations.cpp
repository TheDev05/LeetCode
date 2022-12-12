#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int>> getSub(std::vector<int> num, set<int> inox, std::vector<int> temp, std::vector<std::vector<int>> &result, int index)
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

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n), temp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    set<int> inox;
    std::vector<std::vector<int>> result;

    getSub(num, inox, temp, result, 0);

    for (auto i : result)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }

        std::cout << '\n';
    }
}