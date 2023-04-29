class Solution {
public:
    
    bool wordBreak(string text, vector<string>& num) {
    std::set<std::string> data;
    for (auto i : num)
        data.insert(i);

    std::vector<int> storage(text.size() + 1, 0);
    storage[storage.size() - 1] = 1;
    
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        std::string local;
        int val = 0;
        
        for (int j = i; j < text.size(); j++)
        {
            local += text[j];
            if (data.count(local))
            {
                if (storage[j+1])
                    val = 1;
            }
        }

        storage[i] = val;
    }

    return storage[0];       
    }
};