class Solution {
public:
    long long maximumPoints(vector<int>& num, int total) {

    sort(begin(num), end(num));
    std::deque<int> data;

    for (auto i : num)
        data.push_back(i);

    long long point = 0;
    while (data.size())
    {
        if (total >= data.front())
        {
            point += total / data.front();
            total = total % data.front();
        }
        else if(point > 0)
        {
            total += data.back();
            data.pop_back();
        }else 
             break;
    }

    return point;

    }
}; 
