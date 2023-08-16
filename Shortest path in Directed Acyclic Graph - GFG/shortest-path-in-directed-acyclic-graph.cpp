//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
      void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }

     vector<int> shortestPath(int n,int m, vector<vector<int>>& num){
         
        // code here
    std::vector<std::pair<int, int>> store[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        store[num[i][0]].push_back({num[i][1], num[i][2]});
    }

    // 3 0 2 1
    
    int vis[n]={0};
    
    stack < int > st;
      for (int i = 0; i < n; i++) {
        if (!vis[i]) {
          topoSort(i, store, vis, st);
        }
      }
   
     std::vector<int> res;   
     while(st.size())
     {
         res.push_back(st.top());
         st.pop();
     }

    // for (auto i : res)
    //     std::cout << i << " ";

    std::vector<int> dist(n, 1e6);
    dist[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int node = res[i];
        
        for (auto it: store[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      
    }

    for (auto &i : dist)
        if (i == 1e6)
            i = -1;
            
      return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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