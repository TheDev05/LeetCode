#include <bits/stdc++.h>
using namespace std;

void getComb(std::vector<int> num, std::vector<int> temp, std::vector<std::vector<int>> &inox, int index, int sum, int k)
{
    if (index > num.size())
    {
        return;
    }

    if (sum == k)
    {
        inox.push_back(temp);
    }
    else if (sum < k)
    {
        sum += num[index];
        temp.push_back(num[index]);

        getComb(num, temp, inox, index, sum, k);

        sum -= num[index];
        temp.pop_back();

        getComb(num, temp, inox, index + 1, sum, k);
    }

    return;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n), temp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<std::vector<int>> inox;
    getComb(num, temp, inox, 0, 0, k);

    for (auto i : inox)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}
