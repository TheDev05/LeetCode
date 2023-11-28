class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
    ranges::sort(hbars);
    ranges::sort(vbars);

    int length = 0, width = 0;
    for (int i = 0; i < hbars.size(); i++)
    {
        int index = i;
        while (index < hbars.size() - 1 && hbars[index + 1] - hbars[index] == 1)
            index++;

        length = std::max(length, abs((hbars[index] + 1) - (hbars[i] - 1)));
        i = index;
    }

    for (int i = 0; i < vbars.size(); i++)
    {
        int index = i;
        while (index < vbars.size() - 1 && vbars[index + 1] - vbars[index] == 1)
            index++;

        width = std::max(width, abs((vbars[index] + 1) - (vbars[i] - 1)));
        i = index;
    }

    return pow(std::min(length, width), 2);      
    }
};