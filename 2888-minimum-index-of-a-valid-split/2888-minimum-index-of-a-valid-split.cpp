class Solution {
public:
    int minimumIndex(vector<int>& num) {

    std::map<int, int> data;
    for (auto i : num)
        data[i]++;

    int temp = INT_MIN, val = 0;
    for (auto i : data)
    {
        if (i.second > temp)
            temp = i.second, val = i.first;
    }

    if (temp <= (num.size() / 2))
        return -1;

    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == val)
            count++;

        int left = data[val] - count;
        if (count > (i + 1) / 2 && left > (num.size() - (i + 1)) / 2)
            return i;
    }

    return -1;

    }
};