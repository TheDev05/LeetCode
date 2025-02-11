class Solution {
public:
class dsu
{
public:
    std::vector<int> _size, parent;

    dsu(int n)
    {
        _size.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < _size.size(); i++)
        {
            _size[i] = 1;
            parent[i] = i;
        }
    }

    int getParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = getParent(parent[node]);
    }

    void setUnion(int x, int y)
    {
        int parentDx = parent[x];
        int parentDy = parent[y];

        if (_size[parentDx] > _size[parentDy])
            swap(x, y);

        _size[parent[y]] += _size[parent[x]];
        parent[x] = parent[y];
    }
};
    
    int countBattleships(vector<vector<char>>& num) {
        
    int n = num.size(), m = num[0].size();
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    dsu ds(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 'X')
            {
                vis[i][j] = 1;

                for (int k = 0; k < 4; k++)
                {
                    int row = dx[k] + i;
                    int col = dy[k] + j;

                    if (row >= 0 && row < n && col >= 0 && col < m && num[row][col] == 'X' && vis[row][col] == 0)
                    {
                        int temp1 = (((i + 1) - 1) * m) + j;
                        int temp2 = (((row + 1) - 1) * m) + col;

                        if (ds.getParent(temp1) != ds.getParent(temp2))
                            ds.setUnion(temp1, temp2);

                        vis[row][col] = 1;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = (((i + 1) - 1) * m) + j;
            if (vis[i][j] && ds.parent[temp] == temp)
                count++;
        }
    }

    return count;        
    }
};