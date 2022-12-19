#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<std::vector<int>> &num, int i, int j)
{
    if (i >= num.size())
        return 0;
    if (j >= num[0].size())
        return 0;
    if (num[i][j] == 0)
        return 0;

    int max = 0;
    if (i != 0 && num[i - 1][j] != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        max = std::max(max, fillStore(num, i - 1, j));
        num[i][j] = temp;
    }

    if (i != num.size() - 1 && num[i + 1][j] != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        max = std::max(max, fillStore(num, i + 1, j));
        num[i][j] = temp;
    }

    if (j != 0 && num[i][j - 1] != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        max = std::max(max, fillStore(num, i, j - 1));
        num[i][j] = temp;
    }

    if (j != num[0].size() - 1 && num[i][j + 1] != 0)
    {
        int temp = num[i][j];
        num[i][j] = 0;

        max = std::max(max, fillStore(num, i, j + 1));
        num[i][j] = temp;
    }

    return max + num[i][j];
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(m);
        for (int j = 0; j < m; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] != 0)
            {
                max = std::max(max, fillStore(num, i, j));
            }
        }
    }

    std::cout << max << '\n';
}