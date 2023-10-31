class Solution {
public:
    vector<int> findArray(vector<int>& num) {
        
    std::vector<int> res(1, num[0]);
    int sum = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        res.push_back(sum ^ num[i]);
        sum ^= res.back();
    }

    return res;       
    }
};

    

    

