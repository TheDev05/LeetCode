class Solution {
public:
    int furthestBuilding(vector<int>& num, int bricks, int ladders) {
        
    std::vector<std::pair<int, int>> delta;
    for (int i = 0; i < num.size() - 1; i++)
    {
        if (num[i + 1] - num[i] > 0)
            delta.push_back({num[i + 1] - num[i], i});
    }

    std::set<std::pair<int, int>, greater<std::pair<int, int>>> inox;
    long long sum = 0, res = num.size() - 1;

    for (int i = 0; i < delta.size(); i++)
    {
        if (inox.size() < ladders)
            inox.insert({delta[i].first, i}), sum += delta[i].first;
        else
        {
            if (inox.size() && inox.rbegin()->first < delta[i].first)
                sum -= inox.rbegin()->first,
                    bricks -= inox.rbegin()->first,
                    inox.erase({inox.rbegin()->first, inox.rbegin()->second}),
                    inox.insert({delta[i].first, i}),
                    sum += delta[i].first;
            else
                bricks -= delta[i].first;
        }

        if (bricks < 0)
        {
            res = delta[i].second;
            break;
        }
    }

    return res; 
        
    }
};
