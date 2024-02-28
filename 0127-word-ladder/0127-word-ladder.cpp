class Solution {
public:
    int ladderLength(string start, string end, vector<string>& num) {

    std::unordered_set<std::string> data;
    std::queue<std::string> inox;

    inox.push(start);

    for (auto i : num)
        data.insert(i);

    int ans = 0;
    while (inox.size())
    {
        int size = inox.size();
        ans++;

        for (int idx = 0; idx < size; idx++)
        {
            std::string text = inox.front();
            inox.pop();

            if (text == end)
                return ans;

            std::unordered_set<std::string> store;
            for (auto it = data.begin(); it != data.end(); it++)
            {
                std::string temp = *it;
                if (temp.size() == text.size())
                {
                    int count = 0;
                    for (int j = 0; j < text.size(); j++)
                        if (text[j] != temp[j])
                            count++;

                    if (count == 1)
                        inox.push(temp),
                        store.insert(temp);
                }
            }

            for(auto i: store)
                data.erase(i);
        }
    }

    return 0;
        
    }
};