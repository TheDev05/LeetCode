//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& num, int n,int m, int src){
        // code here
        
    std::vector<int> store[n];
    for (int i = 0; i < m; i++)
    {
        store[num[i][0]].push_back(num[i][1]);
        store[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> dist(n, 1e5 + 1), vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == src)
        {
            dist[src] = 0;
            vis[i] = 1;

            std::queue<int> inox;
            inox.push(i);

            while (inox.size())
            {
                int local = inox.front();
                inox.pop();

                for (auto it : store[local])
                {
                    dist[it] = std::min(dist[it], dist[local] + 1);

                    if (vis[it] == 0)
                    {
                        inox.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    
    for(auto &i: dist) if(i==1e5+1) i = -1;
    
    return dist;
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends