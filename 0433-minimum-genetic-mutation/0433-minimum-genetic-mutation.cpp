class Solution {
public:
    int minMutation(string start, string end, vector<string>& num) {
    
    std::set<std::string> save;
    for (auto i : num)
        save.insert(i);

    if(num.empty() || save.count(end) == false) return -1;

    std::queue<std::string> inox;
    inox.push(start);

    int count = 0;
    while (inox.size())
    {
        int size = inox.size();
        bool ok = false;

        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            save.erase(it);
            inox.pop();

            if (it == end)
            {
                ok = true;
                break;
            }

            for (auto j : save)
            {
                std::string text = j;
                if (text.size() != it.size())
                    continue;

                int temp = 0;
                for (int k = 0; k < text.size(); k++)
                {
                    if (it[k] != text[k])
                        temp++;
                }

                if (temp == 1)
                    inox.push(text);
            }
        }

        if(ok) break;
        count++;
    }

    if(save.count(end) || count == 0) return -1;
    return count;        
    }
};