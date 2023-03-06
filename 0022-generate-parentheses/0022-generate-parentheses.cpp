class Solution {
public:
    int getCount(std::string text, std::vector<std::string> &num, std::set<std::string> &exist, int index)
{
    for (int i = index; i < text.size() - 1; i++)
    {
        if (text[i] == ')')
        {
            for (int j = i + 1; j < text.size(); j++)
            {
                if (text[j] == '(')
                {
                    std::swap(text[i], text[j]);
                    getCount(text, num, exist, i + 1);
                    std::swap(text[i], text[j]);
                }
            }
        }
    }

    if (!exist.count(text))
    {
        exist.insert(text);
        num.push_back(text);
    }

    return 0;
}

    vector<string> generateParenthesis(int n) {
        
    std::string text;
    for (int i = 0; i < n; i++)
    {
        text += "()";
    }

    std::vector<std::string> num;
    std::set<std::string> exist;

    getCount(text, num, exist, 0);
    return num;

    }
};