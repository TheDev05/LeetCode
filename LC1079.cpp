#include <bits/stdc++.h>
using namespace std;

int getSubs(std::string text, std::string temp, std::set<int> inox, std::set<std::string> &result, int index)
{
    if (index >= text.size())
    {
        return 0;
    }

    for (int i = 0; i < text.size(); i++)
    {
        if (inox.count(i) == false)
        {
            inox.insert(i);
            temp += text[i];
            result.insert(temp);

            getSubs(text, temp, inox, result, index + 1);

            inox.erase(i);
            temp.erase(temp.size() - 1);
        }
    }

    return 0;
}

int main()
{
    std::string text;
    std::cin >> text;

    std::string temp;
    std::set<int> inox;
    std::set<std::string> result;

    getSubs(text, temp, inox, result, 0);

    for (auto i : result)
        std::cout << i << " ";
}