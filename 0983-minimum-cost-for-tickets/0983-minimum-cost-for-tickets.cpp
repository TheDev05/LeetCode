class Solution {
public:
int traverse(std::vector<int> &num1, std::vector<int> &num2, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num1.size())
        return 0;
    
    if(k > 365) return 0;

    if (storage[index][k] == -1)
    {
        if (num1[index] < k)
            storage[index][k] = traverse(num1, num2, storage, k, index + 1);
        else
        {
            int val1 = 0, val2 = 0, val3 = 0;
            val1 = num2[0] + traverse(num1, num2, storage, num1[index] + 1, index + 1);
            val2 = num2[1] + traverse(num1, num2, storage, num1[index] + 7, index + 1);
            val3 = num2[2] + traverse(num1, num2, storage, num1[index] + 30, index + 1);

            storage[index][k] = std::min({val1, val2, val3});
        }
    }

    return storage[index][k];
}
    
    int mincostTickets(vector<int>& num1, vector<int>& num2) {
    std::vector<std::vector<int>> storage(num1.size(), std::vector<int>(365 + 1, -1));
    return traverse(num1, num2, storage, 0, 0);        
    }
};