class Solution {
public:
    int minDeletions(string text) {

    std::map<char, int> freq;
    for (auto i : text)
        freq[i]++;

    std::vector<int> sortedFreq;
    for (auto i : freq)
        sortedFreq.push_back(i.second);

    sort(sortedFreq.begin(), sortedFreq.end(), greater<int>());

    int totalRemoval = 0, validFreq = sortedFreq[0];
    for (int i = 0; i < sortedFreq.size(); i++)
    {
        validFreq = (validFreq < 0) ? 0 : validFreq;

        if (sortedFreq[i] > validFreq)
        {
            totalRemoval += abs(validFreq - sortedFreq[i]);
            validFreq--;
        }
        else
            validFreq = sortedFreq[i] - 1;
    }

    return totalRemoval;

    }
};