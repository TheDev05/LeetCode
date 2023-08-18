//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& num, int start, int end) {
        // code here
        
    int mod = 100000;

    std::queue<std::pair<int, int>> inox;
    std::vector<int> dist(mod, 1e7);

    inox.push({start, 0});
    dist[start] = 0;

    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        int val = it.first;
        int lvl = it.second;

        for (auto i : num)
        {
            int prod = (val * i) % mod;
            if (lvl + 1 < dist[prod])
            {
                dist[prod] = lvl + 1;
                inox.push({prod, dist[prod]});
            }

            if (prod == end)
                break;
        }
    }
    
    if(dist[end] == 1e7) return -1;

    return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends