//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& num) {
        // Code here
    int n = num.size(), m = num[0].size();
    std::map<std::pair<int, int>, int> data;

    int inox = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == '1')
                data[{i, j}] = inox;

            inox++;
        }
    }

    std::vector<int> adj[(n * m) + 1];
    for (auto k : data)
    {
        int i = k.first.first, j = k.first.second;
        int index = k.second;

        if (data.count({i + 1, j + 1}))
            adj[index].push_back(data[{i + 1, j + 1}]);
        if (data.count({i - 1, j - 1}))
            adj[index].push_back(data[{i - 1, j - 1}]);

        if (data.count({i + 1, j - 1}))
            adj[index].push_back(data[{i + 1, j - 1}]);
        if (data.count({i - 1, j + 1}))
            adj[index].push_back(data[{i - 1, j + 1}]);

        if (data.count({i + 1, j}))
            adj[index].push_back(data[{i + 1, j}]);
        if (data.count({i - 1, j}))
            adj[index].push_back(data[{i - 1, j}]);

        if (data.count({i, j + 1}))
            adj[index].push_back(data[{i, j + 1}]);
        if (data.count({i, j - 1}))
            adj[index].push_back(data[{i, j - 1}]);

        if (adj[index].empty())
            adj[index].push_back(-1);
    }

    std::vector<int> visited((n * m) + 1, 0);

    int count = 0;
    for (int i = 1; i <= (n * m); i++)
    {
        if (adj[i].size() && !visited[i])
        {
            count++;
            
            if(adj[i][0] == -1) continue;
            std::queue<int> temp;

            temp.push(i);
            visited[i] = 1;

            while (temp.size())
            {
                int dash = temp.front();
                temp.pop();

                for (auto j : adj[dash])
                {
                    if (!visited[j])
                    {
                        visited[j] = 1;
                        temp.push(j);
                    }
                }
            }
        }
    }

    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends