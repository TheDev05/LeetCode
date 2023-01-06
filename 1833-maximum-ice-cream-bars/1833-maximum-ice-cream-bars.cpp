class Solution {
public:
    int maxIceCream(vector<int>& num, int k) {
        
    sort(num.begin(), num.end());

    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (k < num[i])
            break;

        k -= num[i];
        count++;
    }
        
    return count;

    }
};