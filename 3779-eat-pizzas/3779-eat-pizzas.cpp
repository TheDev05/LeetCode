class Solution {
public:
    long long maxWeight(vector<int>& num) {
    sort(num.begin(), num.end(), greater<int>());

    long long sum = 0;
    int total = ceil((double)((num.size() / 4)) / 2);

    for (int i = 0; i < total; i++)
        sum += num[i];
    
    int delta = (num.size() / 4) - total;
    int idx = total;

    while (delta--)
    {
        sum += num[idx + 1];
        idx += 2;
    } 

    return sum;
    }
};
