class Solution {
public:
    int ladderLength(string first, string last, vector<string>& num) {
        
    std::set<std::string> vis, exist;
    std::queue<std::pair<std::string, int>> inox;

    for (auto i : num)
        exist.insert(i);
        
    if(exist.count(last) == false) return 0;

    inox.push({first, 1});
    vis.insert(first);

    int count = 0;
    while (inox.size())
    {
        std::string local = inox.front().first;
        int level = inox.front().second;

        inox.pop();
        if (local == last)
        {
            count = level;
            break;
        }

        for (int i = 0; i < local.size(); i++)
        {
            std::string temp = local;
            char alpha = 'a';

            for (int j = 0; j < 26; j++)
            {
                local[i] = alpha;
                alpha++;

                if (vis.count(local) == false && exist.count(local))
                {
                    vis.insert(local);
                    inox.push({local, level + 1});
                }
            }

            local = temp;
        }
    }
        
    return count;
    }
};