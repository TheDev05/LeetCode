class Solution {
public:
    int minPairSum(vector<int>& num) {
        
    ranges::sort(num);
    int max=0;
        
    [&](){
        for(int i=0;i <num.size()/2;i++) 
            max = std::max(max, num[i]+num[num.size()-1-i]);
    }();
        
    return max;
    }
};