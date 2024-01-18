class Solution {
public:
    void rotate(vector<int>& num, int k) {

    k = k % num.size();
    
    reverse(begin(num), end(num));
    reverse(begin(num), begin(num) + k);
    reverse(begin(num) + k, end(num));
        
    }
};