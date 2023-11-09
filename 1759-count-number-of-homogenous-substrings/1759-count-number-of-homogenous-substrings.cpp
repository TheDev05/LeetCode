class Solution {
public:
    int countHomogenous(string text) {
        
    long long mod = 1e9 + 7, sum = 0;
    for (int i = 0; i < text.size(); i++)
    {
        long long index = i, count = 0;
        while (index < text.size() && text[i] == text[index])
            index++, count++;
        
        sum += ((count * (count + 1)) / 2) % mod;
        i = index - 1;
    }

    return sum;        
    }
};