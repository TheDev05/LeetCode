class Solution {
public:
int getCount(std::string text, std::set<std::string> &exist, int &max, int index)
{
    std::string temp;
    for (int i = index; i < text.size(); i++)
    {
        temp += text[i];
        if (exist.count(temp) == false)
        {
            exist.insert(temp);
            getCount(text, exist, max, i + 1);
            exist.erase(temp);
        }
    }

    max = std::max(max, (int)exist.size());
    return 0;
}

    
    int maxUniqueSplit(string text) {
        
    int max = INT_MIN;
    std::set<std::string> exist;

    getCount(text, exist, max, 0);
    return max;
        
    }
};