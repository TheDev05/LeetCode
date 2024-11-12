class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& num) {

    int max = 0;

    std::vector<std::pair<std::pair<int, int>, int>> data;
    for (int i = 0; i < num.size(); i++)
    {
        int index = i, count = 1;
        while (index < num.size() - 1 && num[index + 1] > num[index])
        {
            index++;
            count++;
        }

        max = std::max(max, count);

        data.push_back({{i, index}, count});
        i = index;
    }

    max = max / 2;

    for (int i = 0; i < data.size(); i++)
    {
        auto [left, right] = data[i].first;
        int count = data[i].second;

        if (i + 1 < data.size() && abs(right - data[i + 1].first.first) == 1)
        {
            max = std::max(max, std::min(count, data[i + 1].second));
        }
    }

    return max;

    }
};