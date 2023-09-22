class Solution {
public:
    string smallestStringWithSwaps(string text, vector<vector<int>>& num) {
    int n = num.size();
        
    std::vector<int> adj[text.size()];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][1]].push_back(num[i][0]);
        adj[num[i][0]].push_back(num[i][1]);
    }

    std::vector<int> vis(text.size(), 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            std::queue<int> inox;

            inox.push(i);
            vis[i] = 1;

            std::string temp;
            std::set<int> index;

            while (inox.size())
            {
                int it = inox.front();
                inox.pop();

                index.insert(it);
                temp += text[it];

                for (auto j : adj[it])
                {
                    if (vis[j] == 0)
                    {
                        vis[j] = 1;
                        inox.push(j);
                    }
                }
            }

            sort(temp.begin(), temp.end());

            int first = 0;
            for (auto p : index)
            {
                text[p] = temp[first];
                first++;
            }
        }
    }

    return text;        
    }
};