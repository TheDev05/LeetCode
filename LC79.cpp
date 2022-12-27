#include <bits/stdc++.h>
using namespace std;

bool getText(std::vector<string> &num, std::string text, int index, int i, int j)
{
    if (index >= text.size() - 1)
    {
        return true;
    }

    if (i != 0 && num[i - 1][j] == text[index + 1])
    {
        char temp = num[i][j];
        num[i][j] = 'x';

        if (getText(num, text, index + 1, i - 1, j))
            return true;

        num[i][j] = temp;
    }

    if (i != num.size() - 1 && num[i + 1][j] == text[index + 1])
    {
        char temp = num[i][j];
        num[i][j] = 'x';

        if (getText(num, text, index + 1, i + 1, j))
            return true;

        num[i][j] = temp;
    }

    if (j != 0 && num[i][j - 1] == text[index + 1])
    {
        char temp = num[i][j];
        num[i][j] = 'x';

        if (getText(num, text, index + 1, i, j - 1))
            return true;

        num[i][j] = temp;
    }

    if (j != num[0].size() - 1 && num[i][j + 1] == text[index + 1])
    {
        char temp = num[i][j];
        num[i][j] = 'x';

        if (getText(num, text, index + 1, i, j + 1))
            return true;

        num[i][j] = temp;
    }

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<char>> num;
    std::string text;

    for (int i = 0; i < n; i++)
    {
        std::vector<char> temp;
        for (int j = 0; j < 4; j++)
        {
            char inox;
            std::cin >> inox;

            temp.push_back(inox);
        }

        num.push_back(temp);
    }

    std::cin >> text;

    std::vector<std::string> data;
    for (int i = 0; i < num.size(); i++)
    {
        std::string temp;
        for (int j = 0; j < num[0].size(); j++)
        {
            temp += num[i][j];
        }

        data.push_back(temp);
    }

    bool ok = false;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            if (data[i][j] == text[0])
            {
                ok |= getText(data, text, 0, i, j);
            }
        }
    }

    std::cout << ok;
}