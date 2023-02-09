class Solution {
public:
int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int pos, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][pos] == -1)
    {
        int val = 0;
        for (int i = index + 1; i < num.size(); i++)
        {
            int ok = 0;
            if (num[i] - num[index] > 0)
                ok = 1;
            else if (num[i] - num[index] < 0)
                ok = 0;
            else
                continue;

            if (index == 0 || pos != ok)
                val = std::max(val, getCount(num, storage, ok, i));
        }

        storage[index][pos] = 1 + val;
    }

    return storage[index][pos];
}

    
    int wiggleMaxLength(vector<int>& num) {
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(2, -1));
    return getCount(num, storage, 1, 0);

    }
};