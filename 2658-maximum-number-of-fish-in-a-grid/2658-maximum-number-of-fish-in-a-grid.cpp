class Solution {
public:

class dsu
{
public:
    std::vector<std::vector<int>> sum;
    std::vector<std::vector<std::pair<int, int>>> parent;

    dsu(int n, int m)
    {
        sum.resize(n + 1, std::vector<int>(m + 1, 0));
        parent.resize(n + 1, std::vector<std::pair<int, int>>(m + 1, {0, 0}));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum[i][j] = 0;
                parent[i][j] = {i, j};
            }
        }
    }

    void setSum(int val, int row, int col)
    {
        sum[row][col] = val;
    }

    std::pair<int, int> getParent(int row, int col)
    {
        if (parent[row][col].first == row && parent[row][col].second == col)
            return {row, col};

        return parent[row][col] = getParent(parent[row][col].first, parent[row][col].second);
    }

    void setSize(int row1, int col1, int row2, int col2)
    {
        auto parent1u = parent[row1][col1];
        auto parent2u = parent[row2][col2];

        if (sum[parent1u.first][parent1u.second] > sum[parent2u.first][parent2u.second])
            std::swap(parent1u, parent2u);

        parent[parent1u.first][parent1u.second] = {parent2u.first, parent2u.second};
        sum[parent2u.first][parent2u.second] += sum[parent1u.first][parent1u.second];
    }
};

    int findMaxFish(vector<vector<int>>& num) {
    
    int n = num.size(), m = num[0].size();
    dsu ds(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ds.setSum(num[i][j], i, j);
        }
    }

    int r[4] = {0, 0, -1, 1};
    int c[4] = {1, -1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int row = i;
            int col = j;

            if (num[row][col])
            {
                for (int k = 0; k < 4; k++)
                {
                    int trow = row + r[k];
                    int tcol = col + c[k];

                    if (trow >= 0 && trow < n && tcol >= 0 && tcol < m &&
                        ds.getParent(row, col) != ds.getParent(trow, tcol) && num[trow][tcol])
                        ds.setSize(row, col, trow, tcol);
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            max = std::max(max, ds.sum[i][j]);
        }
    }

    return max;        
    }
};