class Solution {
public:
    int getCount(std::vector<std::string> &num, std::map<char, int> &exist, std::string text, int &count, int index)
{
    if (index >= num.size())
    {
        count = std::max(count, (int)text.size());
        return 0;
    }

    int size = exist.size();
    for (int i = 0; i < num[index].size(); i++)
    {
        exist[num[index][i]]++;
    }

    if (size + num[index].size() == exist.size())
    {
        getCount(num, exist, text + num[index], count, index + 1);
    }

    for (int i = 0; i < num[index].size(); i++)
    {
        exist[num[index][i]]--;
        if (exist[num[index][i]] == 0)
            exist.erase(num[index][i]);
    }

    getCount(num, exist, text, count, index + 1);
    return 0;
}

    int maxLength(vector<string>& num) {
    std::map<char, int> exist;
    int count = 0;

    std::string text;
    getCount(num, exist, text, count, 0);

    return count;
    }
};