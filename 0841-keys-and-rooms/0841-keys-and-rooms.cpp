class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& num) {
    
    int n = num.size();
    std::vector<int> visited(n, 0);
    std::queue<int> inox;

    visited[0] = 1;
    for (auto i : num[0])
    {
        inox.push(i);
        visited[i] = 1;
    }

    while (inox.size())
    {
        int temp = inox.front();
        inox.pop();

        for (auto i : num[temp])
        {
            if (visited[i] == 0)
            {
                inox.push(i);
                visited[i] = 1;
            }
        }
    }

    bool ok = true;
    for (auto i : visited)
        if (i == 0)
            ok = false;

    if (ok)
        return true;
    else
        return false;        
    }
};