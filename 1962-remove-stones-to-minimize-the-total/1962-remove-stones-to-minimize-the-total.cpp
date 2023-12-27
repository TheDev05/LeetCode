class Solution {
public:
    int minStoneSum(vector<int>& num, int k) {

    std::priority_queue<int> inox;
    for (auto i : num)
        inox.push(i);

    while (k--)
    {
        int temp = inox.top();
        inox.pop();

        inox.push(temp - (temp / 2));
    }

    int sum = 0;
    while (inox.size())
    {
        sum += inox.top();
        inox.pop();
    }

    return sum;  
         
    }
};