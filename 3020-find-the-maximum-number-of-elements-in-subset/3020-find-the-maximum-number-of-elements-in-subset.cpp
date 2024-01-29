class Solution {
public:
    int maximumLength(vector<int>& num) {

    std::map<int, std::map<int, int>> data;
    for (auto i : num)
    {
        int temp = i, prev = i;
        while (temp > 1 && ceil(sqrt(temp)) == floor(sqrt(temp)))
        {
            prev = temp;
            temp = sqrt(temp);
        }

        data[temp][i]++;
    }

    int res = 0;
    if (data.count(1))
        res = data[1][1];

    for (auto i : data)
    {
        int temp = i.second.begin()->first;
        int count = 0;

        for (auto j : i.second)
        {
            if (j.first == temp || j.first == temp * temp)
            {
                if (j.second >= 2)
                    count += 2;
                else
                    count += 1;

                temp = j.first;
                if (j.second == 1)
                    break;
            }
            else
                break;
        }

        res = std::max(res, count);
    }

    if (res % 2 == 0)
        res--;
        
    return res;   

    }
};