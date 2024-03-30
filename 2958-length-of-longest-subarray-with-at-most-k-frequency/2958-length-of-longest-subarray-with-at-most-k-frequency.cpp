class Solution {
public:
    int maxSubarrayLength(vector<int>& num, int k) {
        
    std::map<int, int> data;
    std::map<int, std::set<int>, greater<int>> inox;

    int res = 0, index = 0;
    for (int i = 0; i < num.size(); i++)
    {
        inox[data[num[i]]].erase(num[i]);
        if (inox[data[num[i]]].empty())
            inox.erase(data[num[i]]);
            
        data[num[i]]++;
        inox[data[num[i]]].insert(num[i]);

        while (inox.size() && data.size() && inox.begin()->first > k)
        {
            inox[data[num[index]]].erase(num[index]);
            if (inox[data[num[index]]].empty())
                inox.erase(data[num[index]]);

            data[num[index]]--;
            if (data[num[index]] == 0)
                data.erase(num[index]);
            else
                inox[data[num[index]]].insert(num[index]);

            index++;
        }

        res = std::max(res, (i - index) + 1);
    }

    return res;
        
    }
};