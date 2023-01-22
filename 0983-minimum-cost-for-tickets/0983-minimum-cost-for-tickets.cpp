class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
    std::vector<int> prev(366, 0);
    for (int i = days.size() - 1; i >= 0; i--)
    {
        for (int j = 365; j >= 0; j--)
        {
            int val1 = costs[0], val2 = costs[1], val3 = costs[2];
            if (days[i] < j)
                prev[j] = prev[j];
            else
            {
                if (days[i] + 1 < 366)
                    val1 += prev[days[i] + 1];
                if (days[i] + 7 < 366)
                    val2 += prev[days[i] + 7];
                if (days[i] + 30 < 366)
                    val3 += prev[days[i] + 30];

                prev[j] = std::min({val1, val2, val3});
            }
        }
    }

    return prev[0];
    }
};