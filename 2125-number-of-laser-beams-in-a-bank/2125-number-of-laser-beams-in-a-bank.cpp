class Solution {
public:
    int numberOfBeams(vector<string>& num) {
    std::vector<int> data;
    for (int i = 0; i < num.size(); i++)
    {
        int temp = count(num[i].begin(), num[i].end(), '1');
        if (temp)
            data.push_back(temp);
    }

    if(data.size() <= 1) return 0;

    int sum = 0;
    for (int i = 0; i < data.size() - 1; i++)
    {
        sum += (data[i] * data[i + 1]);
    }

    return sum;        
    }
};