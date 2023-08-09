class Solution {
public:
    int orangesRotting(vector<vector<int>>& num) {
        
    std::vector<std::vector<int>> store(num.size(), std::vector<int>(num[0].size(), 0));
    std::queue<std::pair<int, int>> inox;

    int count1 = 0;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            if (num[i][j] == 2)
                inox.push({i, j});
            else if (num[i][j] == 1)
                count1++;
        }
    }

    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};

    int max = 0, count2 = 0;
    while (inox.size())
    {
        int row = inox.front().first;
        int col = inox.front().second;

        inox.pop();

        for (int i = 0; i < 4; i++)
        {
            int trow = row + r[i];
            int tcol = col + c[i];

            if (trow >= 0 && trow < num.size() && tcol >= 0 && tcol < num[0].size() && num[trow][tcol] == 1 && store[trow][tcol] == 0)
            {
                store[trow][tcol] = store[row][col] + 1;
                inox.push({trow, tcol});

                max = std::max(max, store[trow][tcol]);
                count2++;
            }
        }
    }

    if (count1 != count2)
        max = -1;
        
    return max;       
    }
};