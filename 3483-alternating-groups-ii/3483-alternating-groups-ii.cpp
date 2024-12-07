class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& num, int k) {

    int index = 0, count = 0, sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (i < k)
        {
            if (i && num[i] == num[i - 1])
                count++;
        }
        else
        {
            if (i && num[i] == num[i - 1])
                count++;
            if (index != num.size() - 1 && num[index] == num[index + 1])
                count--;

            index++;
        }

        if ((i - index) + 1 == k && count == 0)
            sum++;
    }

    if (num.front() == num.back())
        return sum;

    std::map<int, int> data1, data2;
    int hole = false;

    for (int i = 0; i < k - 1; i++)
    {
        if (i && num[i] == num[i - 1])
            hole = true;

        if (hole)
            data1[i + 1] = 1;
        else
            data1[i + 1] = 0;
    }

    hole = false;
    for (int i = num.size() - 1; i > num.size() - k; i--)
    {
        if (i != num.size() - 1 && num[i] == num[i + 1])
            hole = true;

        if (hole)
            data2[num.size() - i] = 1;
        else
            data2[num.size() - i + 1] = 0;
    }

    for (auto i : data1)
        if (data2[k - i.first] == 0 && data1[i.first] == 0)
            sum++;

    return sum;

    }
};
