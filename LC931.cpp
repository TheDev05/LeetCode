#include <bits/stdc++.h>
using namespace std;

int findSum(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &res, int i, int j)
{
    if (i == matrix.size() - 1)
    {
        return res[i][j] = matrix[i][j];
    }

    if (res[i][j] != 0)
    {
        return res[i][j];
    }

    int left = INT_MAX, right = INT_MAX, centre = INT_MAX;

    if (j != 0)
    {
        if (res[i + 1][j - 1] == 0)
            left = findSum(matrix, res, i + 1, j - 1);
        else
            left = res[i + 1][j - 1];
    }

    if (j != matrix.size() - 1)
    {
        if (res[i + 1][j + 1] == 0)
            right = findSum(matrix, res, i + 1, j + 1);
        else
            right = res[i + 1][j + 1];
    }

    if (res[i + 1][j] == 0)
        centre = findSum(matrix, res, i + 1, j);
    else
        centre = res[i + 1][j];

    return res[i][j] = matrix[i][j] + std::min({left, right, centre});
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num, temp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> temp[i];
        }

        num.push_back(temp);
    }

    int min = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        min = std::min(min, findSum(num, temp, 0, j));
    }

    std::cout << min << '\n';
}