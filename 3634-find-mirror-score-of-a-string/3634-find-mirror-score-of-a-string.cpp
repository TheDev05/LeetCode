class Solution {
public:
    long long calculateScore(string text) {
        
    int alpha = 'a';
    std::map<int, char> data;

    for (int i = 0; i < 26; i++)
    {
        data[i] = alpha;
        alpha++;
    }

    std::map<char, std::set<int>> num;

    long long sum = 0;
    for (int i = 0; i < text.size(); i++)
    {
        int temp = (int)text[i] - 97;
        int temp1 = 25 - temp;

        char letter = data[temp1];

        if (num.contains(letter))
        {
            auto it = num[letter].rbegin();
            sum += (long long)(i - *it);

            num[letter].erase(*it);
            num[text[i]].erase(i);

            if (num[letter].empty())
                num.erase(letter);
            if (num[text[i]].empty())
                num.erase(text[i]);
        }
        else
            num[text[i]].insert(i);
    }

    return sum; 

    }
};