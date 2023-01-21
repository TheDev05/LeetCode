class Solution {
public:
    int getCount(std::string &text, std::string temp, std::vector<std::string> &result, int k, int index)
{
    if (k < 0)
        return 0;

    std::string inox;
    for (int i = index; i < text.size(); i++)
    {
        inox += text[i];
        if ((long long)stoll(inox) <= 255)
        {
            getCount(text, temp + (inox + '.'), result, k - 1, i + 1);

            if (inox == "0")
                return 0;
        }
    }

    if (temp.size() - 4 == text.size())
        result.push_back(temp.erase(temp.size() - 1));

    return 0;
}

    vector<string> restoreIpAddresses(string text) {
    std::vector<std::string> result;
    std::string temp;

    getCount(text, temp, result, 4, 0);
    return result;
        
    }
};