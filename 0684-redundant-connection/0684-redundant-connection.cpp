class Solution {
public:
class dsu
{
    std::vector<int> _size, parent;

public:
    dsu(int n)
    {
        _size.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
            _size[i] = 1;
        }
    }

    int getParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = getParent(parent[node]);
    }

    void setUnion(int node1, int node2)
    {
        int parent1 = parent[node1];
        int parent2 = parent[node2];

        if (parent1 == parent2)
            return;

        if (_size[parent1] > _size[parent2])
            std::swap(parent1, parent2);

        parent[parent1] = parent[parent2];
        _size[parent2] += _size[parent1];
    }
};

    
    vector<int> findRedundantConnection(vector<vector<int>>& num) {
        
    int n = num.size();
    dsu ds(n);

    std::vector<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        int node1 = num[i][0];
        int node2 = num[i][1];

        if (ds.getParent(node1) == ds.getParent(node2))
        {
            res.push_back(node1);
            res.push_back(node2);
        }
        else
            ds.setUnion(node1, node2);
    } 
        
    return res;
        
    }
};