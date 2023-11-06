class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
    std::stack<int> data;
    std::vector<int> res;

    for (int i = 0; i < num.size(); i++)
        data.push(num[num.size() - 1 - i]);

    for (int i = num.size() - 1; i >= 0; i--)
    {
        while (data.size() && data.top() <= num[i])
        {
            data.pop();
        }

        if (data.size())
            res.push_back(data.top());
        else
            res.push_back(-1);

        data.push(num[i]);
    }

    reverse(begin(res), end(res));
    return res;
    }
};