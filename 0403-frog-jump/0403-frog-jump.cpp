class Solution {
public:
    
int traverse(std::vector<int> &num, std::map<std::pair<int, int>, int> &data, int key, int index)
{
    if (index == num.size() - 1)
        return 1;

    if (data.count({index, key}))
        return data[{index, key}];

    long long k1 = 1e8, k2 = 1e8, k3 = 1e8;
    if (index != 0)
    {
        k2 = key - 1 + num[index];
        k3 = key + 1 + num[index];
    }

    k1 = key + 0 + num[index];

    for (int i = index + 1; i < num.size(); i++)
    {
        if (num[i] > k3)
            break;

        if (num[i] == k1)
        {
            bool ok = false;
            if (data.count({i, key}))
                ok = data[{i, key}];
            else
                ok = traverse(num, data, key, i);

            if (ok)
                return 1;

            data[{i, key}] = ok;
        }
        else if (num[i] == k2)
        {
            bool ok = false;
            if (data.count({i, key - 1}))
                ok = data[{i, key - 1}];
            else
                ok = traverse(num, data, key - 1, i);

            if (ok)
                return 1;

            data[{i, key - 1}] = ok;
        }
        else if (num[i] == k3)
        {
            bool ok = false;
            if (data.count({i, key + 1}))
                ok = data[{i, key + 1}];
            else
                ok = traverse(num, data, key + 1, i);

            if (ok)
                return 1;

            data[{i, key + 1}] = ok;
        }
    }

    return 0;
}
    
    bool canCross(vector<int>& num) {
    std::map<std::pair<int, int>, int> data;
    return traverse(num, data, 1, 0);        
    }
};