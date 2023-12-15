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

    void setUnion(int node1, int node2)
    {
        int parent1 = parent[node1];
        int parent2 = parent[node2];

        if (_size[parent1] < _size[parent2])
            std::swap(node1, node2);

        parent[parent[node2]] = parent[parent[node1]];
        _size[node1] += _size[node2];
    }
};


    bool equationsPossible(vector<string>& num) {

    dsu ds(27);
    for (int i = 0; i < num.size(); i++)
        if (num[i][1] == '=')
            ds.setUnion(((int)(num[i][0] - 97)), ((int)(num[i][3] - 97)));
    

    for(int i = 0; i < num.size(); i++)
        if (num[i][1] == '!' && ds.getParent((int)(num[i][0] - 97)) == ds.getParent((int)(num[i][3] - 97)))
        return false;

    return true;        
    }
};