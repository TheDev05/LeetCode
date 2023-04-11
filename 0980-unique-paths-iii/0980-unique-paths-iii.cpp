class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, int count, int i, int j)
{
    if (num[i][j] == -1)
        return 0;

    if (num[i][j] == 2)
    {
        if (count == -1)
            return 1;
        return 0;
    }

    int sum = 0;
    if (i > 0 && num[i - 1][j] != 1)
    {
        int temp = num[i][j];
        num[i][j] = -1;

        sum += traverse(num, count - 1, i - 1, j);
        num[i][j] = temp;
    }

    if (i < num.size() - 1 && num[i + 1][j] != 1)
    {
        int temp = num[i][j];
        num[i][j] = -1;

        sum += traverse(num, count - 1, i + 1, j);
        num[i][j] = temp;
    }

    if (j > 0 && num[i][j - 1] != 1)
    {
        int temp = num[i][j];
        num[i][j] = -1;

        sum += traverse(num, count - 1, i, j - 1);
        num[i][j] = temp;
    }

    if (j < num[0].size() - 1 && num[i][j + 1] != 1)
    {
        int temp = num[i][j];
        num[i][j] = -1;

        sum += traverse(num, count - 1, i, j + 1);
        num[i][j] = temp;
    }

    return sum;
}
    
    int uniquePathsIII(vector<vector<int>>& num) {
        
    int index1 = 0, index2 = 0, count = 0;
    bool ok = true;

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            if (num[i][j] == 1 && ok)
            {
                index1 = i;
                index2 = j;

                ok = false;
            }

            if (num[i][j] == 0)
                count++;
        }
    }

    return traverse(num, count, index1, index2);        
    }
};