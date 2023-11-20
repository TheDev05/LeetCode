class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    travel.insert(travel.begin(), 0);
    std::map<char, std::pair<int, int>> data;

    int sum = 0, res = 0;
    for (auto &i : travel)
        i += sum, sum = i;

    int idx = 0;
    for (auto i : garbage)
    {
        if (auto count = ranges::count(i, 'G'); count)
            data['G'].first += ranges::count(i, 'G'),
                data['G'].second = travel[idx];
        if (auto count = ranges::count(i, 'P'); count)
            data['P'].first += ranges::count(i, 'P'),
                data['P'].second = travel[idx];
        if (auto count = ranges::count(i, 'M'); count)
            data['M'].first += ranges::count(i, 'M'),
                data['M'].second = travel[idx];

        idx++;
    }

    for (auto [first, second] : data)
        res += second.first + second.second;
        
      return res;
    }
};
