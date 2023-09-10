class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     std::vector<int>less, equal, great;
        
    for(auto i: nums)
    {
        if(i==pivot) equal.push_back(i);
        if(i>pivot) great.push_back(i);
        if(i<pivot) less.push_back(i);  
    }
        
    std::vector<int>res;
    for(auto i: less) res.push_back(i);
    for(auto i: equal) res.push_back(i);
    for(auto i: great) res.push_back(i);
    
    return res;
    }
};