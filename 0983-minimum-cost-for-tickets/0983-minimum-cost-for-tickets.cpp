class Solution {
public:
int getCount(std::vector<int> &days, std::vector<int> &costs, std::vector<std::vector<int>> &storage, int hold, int index)
{
    if (index >= days.size())
        return 0;

    if (storage[index][hold] == -1)
    {
        int val1 = costs[0], val2 = costs[1], val3 = costs[2];
        if (days[index] < hold)
            return (getCount(days, costs, storage, hold, index + 1));
        else
        {
            if (days[index] + 1 < 366)
                val1 += getCount(days, costs, storage, days[index] + 1, index + 1);
            if (days[index] + 7 < 366)
                val2 += getCount(days, costs, storage, days[index] + 7, index + 1);
            if (days[index] + 30 < 366)
                val3 += getCount(days, costs, storage, days[index] + 30, index + 1);
        }

        storage[index][hold] = std::min({val1, val2, val3});
    }

    return storage[index][hold];
}
   
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    std::vector<std::vector<int>> storage(days.size(), std::vector<int>(366, -1));
    return getCount(days, costs, storage, 0, 0);
    }
};