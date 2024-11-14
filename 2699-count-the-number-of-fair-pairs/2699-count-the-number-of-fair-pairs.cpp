class Solution {
public:
    long long countFairPairs(vector<int>& num, int left, int right) {

    sort(begin(num), end(num));

    long long sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int l = (left - num[i]);
        int r = (right - num[i]);

        auto idx1 = lower_bound(num.begin() + i + 1, num.end(), l);
        auto idx2 = upper_bound(num.begin() + i, num.end(), r);

        long long it1 = idx1 - num.begin();
        long long it2 = idx2 - num.begin();

        if (it1 < it2)
            sum += it2 - it1;
    }

    return sum;

    }
};


