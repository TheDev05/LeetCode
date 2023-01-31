class Solution {
public:
    int bestTeamScore(vector<int>& num1, vector<int>& num2) {
    std::vector<std::pair<int, int>> num;
    for (int i = 0; i < num1.size(); i++)
    {
        num.push_back({num2[i], num1[i]});
    }

    sort(num.begin(), num.end());
    std::vector<int> storage(num.size(), 0);

    for (int i = 0; i < num.size(); i++)
    {
        storage[i] = num[i].second;
    }

    int result = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j].second <= num[i].second)
                max = std::max(max, storage[j]);
        }

        storage[i] = num[i].second + max;
        result = std::max(storage[i], result);
    }

    return result;
        
    }
};