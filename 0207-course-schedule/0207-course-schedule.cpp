class Solution {
public:
bool canFinish(int n, vector<vector<int>>& num) {
    
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

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        count++;

        for (auto i : store[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    if (count == n)
        return true;

       return false;       
    }
};