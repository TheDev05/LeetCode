class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& num) {
        
    std::map<int, int> data1, data2;
    std::set<std::pair<int, int>> exist;

    for (int i = 0; i < num.size(); i++)
    {
        if (i <= num.size() / 2)
        {
            data1[num[i][i]]++;
            if (i != num.size() / 2)
                data1[num[i][num[0].size() - 1 - i]]++;

            exist.insert({i, i});
            exist.insert({i, num[0].size() - 1 - i});
        }
        else 
            data1[num[i][num.size() / 2]]++,
                exist.insert({i, num.size() / 2});
    }

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            if (exist.contains({i, j}) == false)
                data2[num[i][j]]++;
        }
    }

    int temp[3] = {0, 1, 2};
    int min = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            int sum1 = 0, sum2 = 0;
            for (auto p : data1)
            {
                if (p.first != temp[i])
                    sum1 += p.second;
                if (p.first != temp[j])
                    sum2 += p.second;
            }

            for (auto q : data2)
            {
                if (q.first != temp[j])
                    sum1 += q.second;
                if (q.first != temp[i])
                    sum2 += q.second;
            }

            min = std::min(min, std::min(sum1, sum2));
        }
    }

    return min;
        
    }
};