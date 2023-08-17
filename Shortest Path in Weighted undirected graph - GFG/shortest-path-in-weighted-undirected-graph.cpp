//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& adj) {
        // Code here
        
    n++;

    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        num[adj[i][1]].push_back({adj[i][0], adj[i][2]});
        
    }

    std::vector<std::pair<int, int>> dist(n, std::pair<int, int>(1e7 + 1, 0));
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> inox;

    inox.push({0, 1});
    dist[1] = {0, 0};

    while (inox.size())
    {
        int node = inox.top().second;
        int wt = inox.top().first;

        inox.pop();

        for (auto it : num[node])
        {
            int adj_node = it.first;
            int adj_wt = it.second;

            if (dist[node].first + adj_wt < dist[adj_node].first)
            {
                dist[adj_node] = {dist[node].first + adj_wt, node};
                inox.push({dist[adj_node].first, adj_node});
            }
        }
    }
    
    if(dist[n-1].first == 1e7 + 1) return {-1};

    std::vector<int> res;
    int temp = n - 1;
    
    while (temp)
    {
        res.push_back(temp);
        temp = dist[temp].second;
    }

    reverse(res.begin(), res.end());
    
    return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends