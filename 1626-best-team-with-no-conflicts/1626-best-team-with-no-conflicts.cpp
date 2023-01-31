class Solution {
public:
    int bestTeamScore(vector<int>& num1, vector<int>& num2) {
    std::vector<std::pair<int, int>> num;
    for (int i = 0; i < num1.size(); i++)
    {
        num.push_back({num2[i], num1[i]});
    }
        
    sort(num.begin(), num.end());
        
    std::vector<int> prev(num.size() + 1, 0), curr(num.size() + 1, 0);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = prev.size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0;
            if (j == 0 || num[i].second >= num[j - 1].second)
                val1 = num[i].second + prev[i + 1];
            val2 = prev[j];

            curr[j] = std::max(val1, val2);
        }

        prev = curr;
    }

    return curr[0];
        
    }
};