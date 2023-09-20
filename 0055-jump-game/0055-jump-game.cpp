class Solution {
public:
int traverse(std::vector<int> &num, std::vector<int> &storage, int index)
{
    if (index == num.size() - 1)
        return 1;

    if (index >= num.size())
        return 0;

    if (storage[index] == -1)
    {
        for (int i = 1; i <= num[index]; i++)
        {
            if (traverse(num, storage, index + i))
                return 1;
        }
    }

    return storage[index] = 0;
}

    bool canJump(vector<int>& num) {
    std::vector<int> storage(num.size() + 1, -1);
    return traverse(num, storage, 0);      
    }
};