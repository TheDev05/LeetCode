//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& num,
                 int lim) {
                     
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e7));
    for (int i = 0; i < m; i++)
    {
        dist[num[i][0]][num[i][1]] = num[i][2];
        dist[num[i][1]][num[i][0]] = num[i][2];
    }

    for (int v = 0; v < n; v++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][v] + dist[v][j]);
                if(i == j) dist[i][j] = 0;
            }
        }
    }

    std::vector<int> inox(n, 0);

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] && dist[i][j] <= lim)
                count++;
        }

        inox[i] = count;
        min = std::min(min, count);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (inox[i] == min)
            max = std::max(max, i);
    }       
    
    return max;
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends