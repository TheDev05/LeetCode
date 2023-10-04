class Solution {
public:
static bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

    
    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& stud, int total) {
        
    std::set<std::string> success, fail;
    for (auto i : pos)
        success.insert(i);

    for (auto i : neg)
        fail.insert(i);

    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < report.size(); i++)
    {
        std::string     temp;
        int sum = 0;

        for (int j = 0; j < report[i].size(); j++)
        {
            if (report[i][j] != ' ')
                temp += report[i][j];

            if (report[i][j] == ' ' || j == report[i].size() - 1)
            {

                if (success.count(temp))
                    sum += 3;
                if (fail.count(temp))
                    sum -= 1;

                temp.clear();
            }
        }

        res.push_back({sum, stud[i]});
    }

    sort(res.begin(), res.end(), cmp);

    std::vector<int> result;
    int count = 0;

    for (auto i : res)
        if (count < total)
        {
            result.push_back(i.second);
            count++;
        }

    return result;        
    }
};