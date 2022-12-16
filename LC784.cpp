#include <bits/stdc++.h>
using namespace std;

int getSubs(std::string text, std::string temp, std::vector<string> &data, int index)
{
    if (index >= text.size())
    {
        data.push_back(temp);
        return 0;
    }

    if (text[index] >= 'a' && text[index] <= 'z')
    {
        temp += text[index];
        getSubs(text, temp, data, index + 1);
        temp.erase(temp.size() - 1);

        temp += toupper(text[index]);
        getSubs(text, temp, data, index + 1);
    }
    else if (text[index] >= 'A' && text[index] <= 'Z')
    {
        temp += text[index];
        getSubs(text, temp, data, index + 1);
        temp.erase(temp.size() - 1);

        temp += tolower(text[index]);
        getSubs(text, temp, data, index + 1);
    }
    else
    {
        temp += text[index];
        getSubs(text, temp, data, index + 1);
    }

    return 0;
}

int main()
{
    std::string text;
    std::cin >> text;

    std::vector<string> data;
    std::string temp;

    getSubs(text, temp, data, 0);

    for (auto i : data)
        std::cout << i << " ";
}