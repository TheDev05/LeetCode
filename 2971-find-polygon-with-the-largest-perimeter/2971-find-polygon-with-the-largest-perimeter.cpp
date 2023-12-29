class Solution {
public:
    long long largestPerimeter(vector<int>& num) {
    ranges::sort(num);
        
    long long sum = accumulate(begin(num), end(num), (long long)0);
    long long temp = 0;
        
    for(int i = num.size() - 1; i >= 0; i--)
    {
        temp += num[i];
        long long delta = sum - temp;
        
        if(delta > num[i]) return delta + num[i];
    }
        
    return -1;        
    }
};