class Solution {
public:
    bool isPalin(std::string text)
{
    for (int i = 0; i < text.size() / 2; i++)
    {
        if (text[i] != text[text.size() - 1 - i])
            return false;
    }

    return true;
}

int getCount2(std::string &text, std::string &temp, int &count, int index)
{
    for (int i = index; i < text.size(); i++)
    {
        if (text[i] != '0')
        {
            char local = text[i];
            temp += text[i];
            text[i] = '0';

            getCount2(text, temp, count, i + 1);

            temp.erase(temp.size() - 1);
            text[i] = local;
        }
    }

    if (isPalin(temp))
    {
        count = std::max(count, (int)temp.size());
    }

    return 0;
}

int getCount(std::string &text, std::string temp, int &count, int index)
{
    for (int i = index; i < text.size(); i++)
    {
        char local = text[i];
        temp += text[i];
        text[i] = '0';

        getCount(text, temp, count, i + 1);

        temp.erase(temp.size() - 1);
        text[i] = local;
    }

    if (isPalin(temp))
    {
        std::string temp2;
        int count2 = 0;

        getCount2(text, temp2, count2, 0);
        count = std::max(count, (int)(temp.size() * count2));
    }

    return 0;
}

    
    int maxProduct(string text) {
        
    int count = 0;
    std::string temp;

    getCount(text, temp, count, 0);
    return count;
        
    }
};

