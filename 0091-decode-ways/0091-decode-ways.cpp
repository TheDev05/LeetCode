class Solution {
public:

    int numDecodings(string text) {
    std::vector<int> storage(text.size() + 1, 0);
    
    storage[text.size()] = 1;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        std::string temp;

        int val1 = 0;
        for (int j = i; j < text.size(); j++)
        {
            temp += text[j];
            if (temp.size() < 3 && stoi(temp) == 0)
                break;
            if (temp.size() < 3 && stoi(temp) < 27)
                val1 += storage[j + 1];
        }

        storage[i] = val1;
    }

    return storage[0];

    }
};