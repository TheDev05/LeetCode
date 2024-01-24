class Solution {
public:
    
    int traverse(std::vector<std::string> &num, std::set<char> &data, int index)
    {
        if (index >= num.size())
            return data.size();

        bool ok = true;
        for (auto i : num[index])
        {
            if (data.contains(i))
            {
                ok = false;
                break;
            }
        }

        int val1 = 0, val2 = 0, size = data.size();
        if (ok)
        {
            for (auto i : num[index])
                data.insert(i);

            if(data.size() == size + num[index].size())
                val1 = traverse(num, data, index + 1);

            for (auto i : num[index])
                data.erase(i);
        }

        val2 = traverse(num, data, index + 1);
        return std::max(val1, val2);
    }
    
    int maxLength(vector<string>& num) {
        
    std::set<char> data;
    return traverse(num, data, 0);   
        
    }
};