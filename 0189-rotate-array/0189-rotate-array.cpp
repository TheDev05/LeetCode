class Solution {
public:
    void rotate(vector<int>& num, int k) {

    k = k % num.size();

    std::vector<int> res;
    for (int i = num.size() - k; i < num.size(); i++)
        res.push_back(num[i]);

    for (int i = 0; i < num.size() - k; i++)
        res.push_back(num[i]);

    num = res;
        
    }
};