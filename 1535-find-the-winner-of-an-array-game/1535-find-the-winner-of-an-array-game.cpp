class Solution {
public:
    int getWinner(vector<int>& num, int k) {
        
    std::deque<int> data;
    for (auto i : num)
        data.push_back(i);

    std::map<int, int> inox;
    int index = 0;

    while (index++ < num.size())
    {
        if (data.size() == 1)
            break;

        if (data[0] > data[1])
            swap(data[0], data[1]);

        data.push_back(data[0]);
        data.pop_front();

        inox[data[0]]++;
        if (inox[data[0]] >= k)
            return data[0];
    }

    return *max_element(begin(num), end(num));       
    }
};