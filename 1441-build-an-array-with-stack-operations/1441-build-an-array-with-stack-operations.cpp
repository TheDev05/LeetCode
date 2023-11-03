class Solution {
public:
    vector<string> buildArray(vector<int>& num, int n) {
        
    std::vector<std::string> res;
    int temp = 0;

    for (int i = 0; i < num.size(); i++)
    {
        int count = abs(temp - num[i]);

        for (int j = 0; j < count - 1; j++)
            res.push_back("Push"), res.push_back("Pop");

        res.push_back("Push");
        temp = num[i];
    }
        
        return res;
    }
};