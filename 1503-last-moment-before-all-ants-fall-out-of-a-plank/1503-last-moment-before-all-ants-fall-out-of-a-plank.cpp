class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
    int maxR = n, maxL = 0;
        
    if(right.size())
        maxR=*min_element(begin(right), end(right));
    if(left.size())
        maxL=*max_element(begin(left), end(left));
        
    return std::max(abs(n-maxR), abs(0-maxL));
    }
};