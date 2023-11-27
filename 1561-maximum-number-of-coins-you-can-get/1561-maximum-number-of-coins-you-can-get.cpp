class Solution {
public:
    int maxCoins(vector<int>& num) {
        ranges::sort(num, greater());        
        int sum=0, count = num.size()/3;
        
        for(int i=0;i<num.size();i++)
            if((i&1) && count) sum+=num[i], count--;
                
        return sum;
    }
};
