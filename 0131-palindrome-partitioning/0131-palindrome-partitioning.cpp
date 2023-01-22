class Solution {
public:
bool isValid(std::string text)
{
    for (int i = 0; i < text.size() / 2; i++)
    {
        if (text[i] != text[text.size() - 1 - i])
            return false;
    }

    return true;
}

int getText(std::string text, std::vector<std::string> &temp, std::vector<std::vector<std::string>> &num, int index)
{
    if (index >= text.size())
    {
        num.push_back(temp);
        return 0;
    }

    std::string local;
    for (int i = index; i < text.size(); i++)
    {
        local += text[i];
        if (isValid(local))
        {
            temp.push_back(local);
            getText(text, temp, num, i + 1);
            temp.pop_back();
        }
    }

    return 0;
}


    vector<vector<string>> partition(string text) {

    std::vector<std::string> temp;
    std::vector<std::vector<std::string>> num;

    getText(text, temp, num, 0);
    return num;
    
    }
};