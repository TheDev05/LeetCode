class Solution {
public:

void traverse(std::string text, std::set<std::string> &vis, std::map<std::string, std::set<int>> &data, std::vector<std::vector<std::string>> &num, std::set<std::string> &res)
{
    vis.insert(text);
    for (auto i : data[text])
    {
        for (int j = 1; j < num[i].size(); j++)
        {
            if (vis.count(num[i][j]) == false)
                traverse(num[i][j], vis, data, num, res);
        }
    }

    res.insert(text);
}

    vector<vector<string>> accountsMerge(vector<vector<string>>& num) {

    std::map<std::string, std::set<int>> data;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 1; j < num[i].size(); j++)
        {
            data[num[i][j]].insert(i);
        }
    }

    std::set<std::string> vis;
    std::vector<std::vector<std::string>> result;

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 1; j < num[i].size(); j++)
        {
            if (vis.count(num[i][j]) == false)
            {
                std::set<std::string> res;
                std::vector<std::string>temp(1, num[i][0]);

                traverse(num[i][j], vis, data, num, res);
                for(auto k: res) temp.push_back(k);

                result.push_back(temp);
            }
        }
    }

    return result;        
    }
};