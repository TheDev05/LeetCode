#include <bits/stdc++.h>
using namespace std;

bool isPalin(std::string text)
{
    for (int i = 0; i < text.size() / 2; i++)
    {
        if (text[i] != text[text.size() - 1 - i])
            return false;
    }

    return true;
}

int getSubs(std::string text, std::vector<string> &temp, std::vector<std::vector<string>> &num, int index)
{
    if (index >= text.size())
    {
        num.push_back(temp);
        return 0;
    }

    string inox;
    for (int i = index; i < text.size(); i++)
    {
        inox += text[i];
        if (isPalin(inox))
        {
            temp.push_back(inox);
            getSubs(text, temp, num, i + 1);
            temp.pop_back();
        }
    }

    return 0;
}

int main()
{
    std::string text;
    std::cin >> text;

    std::vector<string> temp;
    std::vector<std::vector<string>> num;

    getSubs(text, temp, num, 0);

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}