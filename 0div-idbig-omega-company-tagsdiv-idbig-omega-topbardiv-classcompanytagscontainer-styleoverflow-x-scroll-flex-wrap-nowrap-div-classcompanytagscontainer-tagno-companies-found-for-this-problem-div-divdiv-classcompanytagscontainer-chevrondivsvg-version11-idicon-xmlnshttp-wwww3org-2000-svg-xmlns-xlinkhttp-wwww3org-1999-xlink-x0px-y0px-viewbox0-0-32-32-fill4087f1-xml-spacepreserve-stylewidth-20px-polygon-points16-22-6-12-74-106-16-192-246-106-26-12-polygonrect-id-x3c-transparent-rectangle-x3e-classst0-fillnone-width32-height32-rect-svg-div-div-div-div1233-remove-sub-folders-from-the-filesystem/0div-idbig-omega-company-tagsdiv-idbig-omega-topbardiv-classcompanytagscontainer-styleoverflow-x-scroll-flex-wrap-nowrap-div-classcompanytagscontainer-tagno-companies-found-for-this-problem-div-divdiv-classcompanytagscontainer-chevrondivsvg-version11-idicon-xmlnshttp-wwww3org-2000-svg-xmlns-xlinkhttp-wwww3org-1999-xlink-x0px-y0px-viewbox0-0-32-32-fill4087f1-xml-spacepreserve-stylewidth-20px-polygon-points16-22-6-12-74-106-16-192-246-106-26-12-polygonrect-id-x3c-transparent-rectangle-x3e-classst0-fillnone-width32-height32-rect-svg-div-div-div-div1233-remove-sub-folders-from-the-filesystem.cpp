class Solution {
public:
    vector<string> removeSubfolders(vector<string>& num) {

    int n = num.size();
    sort(num.begin(), num.end());
    
    std::set<std::string> data;
    std::vector<std::string> res;
    for (int i = 0; i < n; i++)
    {
        std::string text;
        bool ok = true;
        for (int j = 0; j < num[i].size(); j++)
        {
            if (num[i][j] == '/' && data.count(text))
            {
                ok = false;
                break;
            }

            text += num[i][j];
        }

        if (ok)
        {
            res.push_back(num[i]);
            data.insert(num[i]);
        }
    }

    return res;

    }
};