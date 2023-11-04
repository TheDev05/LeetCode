class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& num) {
        
    std::vector<std::pair<int, int>> data;
    for (int i = 0; i < num.size(); i++)
    {
        data.push_back({num[i][0], num[i][1]});
    }

    sort(begin(data), end(data));

    int left = 0, right = 0, count = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (count == 0)
        {
            count++;

            left = data[i].first;
            right = data[i].second;
        }
        else
        {
            if (data[i].first <= right)
            {
                left = std::max(left, data[i].first);
                right = std::min(right, data[i].second);
            }
            else
            {
                count++;

                left = data[i].first;
                right = data[i].second;
            }
        }
    }

    return count;        
    }
};