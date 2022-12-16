#include <bits/stdc++.h>
using namespace std;

void genSubs(std::vector<int> num, std::vector<int> temp, std::vector<std::vector<int>> &result, int index)
{
    if (index >= num.size())
    {
        result.push_back(temp);
        return;
    }

    temp.push_back(num[index]);
    genSubs(num, temp, result, index + 1);

    temp.pop_back();
    genSubs(num, temp, result, index + 1);

    return;
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

    std::vector<int> temp;
    std::vector<std::vector<int>> result;
    genSubs(num, temp, result, 0);

    for (auto i : result)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}