class Solution {
public:
    int minSteps(string text1, string text2) {
        
    std::map<char, int> data1, data2;
    for (auto i : text1)
        data1[i]++;

    for (auto i : text2)
        data2[i]++;

    int sum = 0;
    for (auto i : text2)
    {
        if (data1.contains(i))
        {
            if (--data1[i] == 0)
                data1.erase(i);
        }
        else
            sum++;
    }

    for (auto i : text1)
    {
        if (data2.contains(i))
        {
            if (--data2[i] == 0)
                data2.erase(i);
        }
        else
            sum++;
    }

    return sum;        
    }
};