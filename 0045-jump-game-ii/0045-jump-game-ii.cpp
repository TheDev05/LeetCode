class Solution {
public:
int getCount(std::vector<int> &num, std::vector<int> &storage, int index)
{
    if (index == num.size() - 1)
        return 0;

    if (storage[index] == -1)
    {
        int val = 1e5;
        for (int i = 1; i <= num[index]; i++)
        {
            if (index + i < num.size())
            {
                val = std::min(val, getCount(num, storage, index + i));
            }
            else
                break;
        }

        storage[index] = 1 + val;
    }

    return storage[index];
}  
    int jump(vector<int>& num) {
    std::vector<int> storage(num.size(), -1);
    return getCount(num, storage, 0);  
        
    }
};