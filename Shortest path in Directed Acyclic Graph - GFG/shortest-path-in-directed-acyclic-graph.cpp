//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& num){
         
        // code here
    std::vector<std::pair<int, int>> store[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        store[num[i][0]].push_back({num[i][1], num[i][2]});
    }

    for (auto i : store)
    {
        for (auto j : i)
            indeg[j.first]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::vector<int> res;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        res.push_back(local);

        for (auto i : store[local])
        {
            indeg[i.first]--;
            if (indeg[i.first] == 0)
                inox.push(i.first);
        }
    }

    std::vector<int> dist(n, 1e6);
    dist[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto j : store[res[i]])
        {
            dist[j.first] = std::min(dist[j.first], dist[res[i]] + j.second);
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