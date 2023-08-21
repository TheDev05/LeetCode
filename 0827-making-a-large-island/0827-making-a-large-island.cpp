class Solution {
public:
    
class dsu
{
public:
    std::vector<int> parent, _size;
    dsu(int n)
    {
        parent.resize(n + 1, 0);
        _size.resize(n + 1, 0);

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
            _size[i] = 1;
        }
    }

    int getParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = getParent(parent[u]);
    }

    void setUnion(int u, int v)
    {
        int uroot = parent[u];
        int vroot = parent[v];

        if (uroot != vroot)
        {
            if (_size[vroot] < _size[uroot])
                std::swap(uroot, vroot);

            parent[uroot] = vroot;
            _size[vroot] += _size[uroot];
        }
    }
};
  
    int largestIsland(vector<vector<int>>& num) {
    
    int n = num.size();
    dsu ds(n * n);

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (num[i][j])
            {
                int row = i;
                int col = j;

                for (int k = 0; k < 4; k++)
                {
                    int trow = row + r[k];
                    int tcol = col + c[k];

                    if (trow >= 0 && tcol >= 0 && trow < n && tcol < n && num[trow][tcol])
                    {
                        int u = (n * row) + col;
                        int v = (n * trow) + tcol;

                        if (ds.getParent(u) != ds.getParent(v))
                            ds.setUnion(u, v);
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n * n; i++)
    {
        max = std::max(max, ds._size[ds.getParent(i)]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            if (num[i][j] == 0)
            {
                int row = i;
                int col = j;

                std::set<int> temp;
                for (int k = 0; k < 4; k++)
                {
                    int trow = row + r[k];
                    int tcol = col + c[k];

                    if (trow >= 0 && tcol >= 0 && trow < n && tcol < n && num[trow][tcol])
                    {
                        int u = (n * row) + col;
                        int v = (n * trow) + tcol;

                        temp.insert(ds.getParent(v));
                    }
                }

                for (auto p : temp)
                    sum += ds._size[p];

                max = std::max(max, sum + 1);
            }
        }
    }
    
    return max;
        
    }
};