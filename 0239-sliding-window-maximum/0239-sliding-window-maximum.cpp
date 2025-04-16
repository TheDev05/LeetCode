class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int k) {

    std::map<int, int> data;
    for (int i = 0; i < k; i++)
    {
        data[num[i]]++;
    }

    std::vector<int> result;
    result.push_back(data.rbegin()->first);

    int index = 0;
    for (int i = k; i < num.size(); i++)
    {
        data[num[i]]++;

        if (--data[num[index]] == 0)
        {
            data.erase(num[index]);
        }

        result.push_back(data.rbegin()->first);

        index++;
    }

    return result;

    }
};