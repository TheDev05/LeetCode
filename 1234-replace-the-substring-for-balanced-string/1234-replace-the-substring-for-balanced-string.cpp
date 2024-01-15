class Solution {
public:
    bool validate(std::map<char, int> &inox, std::map<char, int> &temp)
    {
        for (auto i : inox)
            if (temp.contains(i.first) && temp[i.first] >= i.second)
                continue;
            else
                return false;

        return true;
    }

    int balancedString(string text) {
        
    int k = text.size() / 4;
    std::map<char, int> data;

    for (auto i : text)
        data[i]++;

    std::map<char, int> inox;
    for (auto i : data)
        if (i.second > k)
            inox[i.first] = i.second - k;

    if (inox.empty())
        return 0;

    std::map<char, int> temp;
    int index = 0, min = INT_MAX;

    for (int i = 0; i < text.size(); i++)
    {
        if (inox.contains(text[i]))
            temp[text[i]]++;

        while (validate(inox, temp))
        {
            min = std::min(min, (i - index) + 1);
            if (inox.contains(text[index]) && --temp[text[index]] == 0)
                temp.erase(text[index]);

            index++;
        }
    }

    return min;        
    }
};
