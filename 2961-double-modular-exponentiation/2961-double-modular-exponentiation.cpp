class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& num, int target) {
    auto get = [&](int a, int b, int c, auto &get)
    {
        if (b == 0)
            return 1;
        else if (b & 1)
            return ((a % c) * get(a, b - 1, c, get)) % c;
        else
        {
            int temp = get(a, b / 2, c, get);
            return (temp * temp) % c;
        }
    };

    std::vector<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        int a = num[i][0], b = num[i][1], c = num[i][2], d = num[i][3];

        int temp1 = get(a, b, 10, get);
        int temp2 = get(temp1, c, d, get);

        if (temp2 == target)
            res.push_back(i);
    }
        
    return res;
    }
};