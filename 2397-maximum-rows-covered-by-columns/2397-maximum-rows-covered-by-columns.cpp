class Solution {
public:
    int getRow(std::vector<std::vector<int>> &num, std::set<int> &col)
{
    int sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < num[0].size(); j++)
        {
            if (num[i][j] == 1 && col.count(j) == false)
            {
                ok = false;
            }
        }

        if (ok)
        {
            sum++;
        }
    }

    return sum;
}

int getCount(std::vector<std::vector<int>> &num, std::set<int> &col, int &count, int sum, int k, int index)
{
    for (int i = index; i < num[0].size(); i++)
    {
        if (col.size() > k)
            break;

        col.insert(i);
        getCount(num, col, count, sum, k, i + 1);
        col.erase(i);
    }

    if (col.size() == k)
    {
        int val = getRow(num, col);
        count = std::max(count, val);
    }

    return 0;
}


    int maximumRows(vector<vector<int>>& num, int k) {
    std::set<int> col;
    int count = 0;

    getCount(num, col, count, 0, k, 0);
    return count;
    
    }
};