class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& num) {
        
    std::vector<int> store[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < num.size(); i++)
    {
        store[num[i][1]].push_back(num[i][0]);
        indeg[num[i][0]]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::vector<int>topo;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        topo.push_back(local);

        for (auto i : store[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }  
    
    if(topo.size() == n)
    return topo;
    
    return {};
        
    }
};