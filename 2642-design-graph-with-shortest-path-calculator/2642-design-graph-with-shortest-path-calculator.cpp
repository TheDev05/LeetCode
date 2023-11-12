class Graph {
public:
    std::vector<std::vector<std::pair<int,int>>>num;
    Graph(int n, vector<vector<int>>& edges) {
        
        num.resize(n);
        for(int i=0; i<edges.size();i++)
        {
            num[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        num[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>>inox;
        std::vector<int>dist(num.size(), INT_MAX);
        
        inox.push({0, node1});
        dist[node1]=0;
            
        while(inox.size())
        {
            auto [val, node] = inox.top();
            inox.pop();
            
            if(node == node2) return val;
            
            for(auto i: num[node])
            {
                if(dist[node] + i.second < dist[i.first])
                {
                    dist[i.first]=dist[node]+i.second;
                    inox.push({dist[i.first], i.first});
                }
            }
        }
        
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */