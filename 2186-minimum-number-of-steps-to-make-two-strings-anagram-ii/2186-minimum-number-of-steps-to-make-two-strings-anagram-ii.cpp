class Solution {
public:
    int minSteps(string text1, string text2) {
        
    std::map<char, int> mp1, mp2;
    for (auto i : text1)
        mp1[i]++;

    for (auto i : text2)
        mp2[i]++;

    int sum = 0;
    for (auto i : mp1)
        if (mp2.contains(i.first))
            sum += abs(i.second - mp2[i.first]), mp2.erase(i.first);
        else
            sum += i.second;

    for (auto i : mp2)
        sum += i.second;

    return sum;        
    }
};