class Solution {
public:
int getCount(std::string text, std::string temp, int count, std::set<std::string> &exist, std::vector<std::string> &result, int index)
{
    std::string local;
    for (int i = index; i < text.size(); i++)
    {
        local += text[i];
        if (exist.count(local))
        {
            local += " ";
            getCount(text, temp + local, count + 1, exist, result, i + 1);
            local.erase(local.size() - 1);
        }
    }

    if (temp.size() - count == text.size())
    {
        temp.erase(temp.size() - 1);
        result.push_back(temp);
    }
    
    return 0;
}

    
    vector<string> wordBreak(string text, vector<string>& num) {
        
    std::set<std::string> exist;
    std::vector<std::string> result;

    for (auto i : num)
        exist.insert(i);

    std::string temp;
    getCount(text, temp, 0, exist, result, 0);
        
    return result;
        
    }
};