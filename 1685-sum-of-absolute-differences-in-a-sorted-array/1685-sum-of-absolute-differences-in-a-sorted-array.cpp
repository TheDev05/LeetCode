class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& num) {
        int sum = accumulate(begin(num), end(num), 0);
        std::vector<int>res;
        ranges::sort(num);
        
        int temp=0;
        for(int i=0;i<num.size();i++)
        {
            int val1 = (num[i]*i)-temp;
            temp += num[i];
            
            int val2=(sum-temp)-((num[i]*(num.size() - (i+1))));             
            res.push_back(val1+val2);
        }
        
        return res;
    }
};

// 1 2 3 4 5 : 15
// 4-3, 5-3, 3-2, 3-1