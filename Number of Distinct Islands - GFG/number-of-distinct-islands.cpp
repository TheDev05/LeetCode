//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& num) {
        // code here
        
    int n = num.size(), m = num[0].size();
    
    std::set<std::set<std::pair<int, int>>> inox;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] && vis[i][j] == 0)
            {
                std::queue<std::pair<int, int>> temp;
                std::set<std::pair<int, int>> store;

                temp.push({i, j});
                vis[i][j] = 1;

                int left = i, right = j;
                while (temp.size())
                {
                    int row = temp.front().first;
                    int col = temp.front().second;

                    temp.pop();
                    store.insert({abs(row - left), (col - right)});

                    for (int k = 0; k < 4; k++)
                    {
                        int trow = row + r[k];
                        int tcol = col + c[k];

                        if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] && !vis[trow][tcol])
                        {
                            vis[trow][tcol] = 1;
                            temp.push({trow, tcol});
                        }
                    }
                }

                inox.insert(store);
            }
        }
    }

    return inox.size();
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends