class Solution {
public:
    long long sumDigitDifferences(vector<int>& temp) {
   
    std::vector<std::string> num;
    for (auto &i : temp)
        num.push_back(to_string(i));

    std::map<int, std::map<char, int>> data;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            data[j][num[i][j]]++;
        }
    }

    long long sum = 0;
    for (auto i : data)
    {
        long long total = num.size();
        for (auto j : i.second)
        {
            sum += j.second * (total - j.second);
            total -= j.second;
        }
    }

    return sum;   

    }
};