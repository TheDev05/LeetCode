class Solution {
public:
    string replaceWords(vector<string>& num, string text) {
        
    std::vector<std::string> data;
    std::string temp;

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
            data.push_back(temp), temp.clear();
        else
            temp += text[i];

        if (i == text.size() - 1)
            data.push_back(temp);
    }

    std::set<std::string> inox;
    for (auto i : num)
        inox.insert(i);

    std::string result;
    for (int i = 0; i < data.size(); i++)
    {
        std::string temp;
        for (int j = 0; j < data[i].size(); j++)
        {
            temp += data[i][j];

            if (inox.count(temp))
            {
                data[i] = *inox.find(temp);
                break;
            }
        }
        
        if(i) result += " ";
        result += data[i];
    }
    
    return result;
    }
};