class Solution {
public:
    
    vector<string> shortestSubstrings(vector<string>& num) {
        
    std::map<std::string, int> data;
    std::map<int, std::vector<std::string>> inox;

    for (int i = 0; i < num.size(); i++)
    {
        std::string text = num[i];
        for (int j = 0; j < text.size(); j++)
        {
            std::string temp;
            for (int k = j; k < text.size(); k++)
            {
                temp += text[k];

                data[temp]++;
                inox[i].push_back(temp);
            }
        }
    }

    std::vector<std::string> res;
    for (int i = 0; i < num.size(); i++)
    {
        for (auto j : inox[i])
            if (--data[j] == 0)
                data.erase(j);

        std::string temp = "";
        for (auto k : inox[i])
        {
            if (data.contains(k) == false)
            {
                if (temp == "")
                    temp = k;

                if (k.size() == temp.size())
                    temp = std::min(temp, k);
                else if (k.size() < temp.size())
                    temp = k;
            }
        }

        res.push_back(temp);

        for (auto j : inox[i])
            data[j]++;
    }
        
    return res;
        
    }
    
};