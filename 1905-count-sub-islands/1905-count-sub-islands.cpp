class Solution {
public:
    int countSubIslands(vector<vector<int>>& num1, vector<vector<int>>& num2) {
    
    int n = num1.size(), m = num1[0].size();
        
    std::vector<std::pair<int, int>> inox;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num2[i][j])
                inox.push_back({i, j});
        }
    }

    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> store;

    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};

    int count = 0;
    for (int i = 0; i < inox.size(); i++)
    {
        int row = inox[i].first;
        int col = inox[i].second;

        if (visited[row][col] == 0)
        {
            visited[row][col] = 1;
            store.push({row, col});

            bool ok = true;
            while (store.size())
            {
                int nrow = store.front().first;
                int ncol = store.front().second;

                store.pop();
                if (num1[nrow][ncol] == 0)
                    ok = false;

                for (int j = 0; j < 4; j++)
                {
                    int trow = nrow + r[j];
                    int tcol = ncol + c[j];

                    if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && visited[trow][tcol] == 0 && num2[trow][tcol])
                    {
                        visited[trow][tcol] = 1;
                        store.push({trow, tcol});
                    }
                }
            }

            if (ok)
                count++;
        }
    }

    return count;        
    }
};