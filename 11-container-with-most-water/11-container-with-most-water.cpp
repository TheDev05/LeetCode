class Solution {
public:
    int maxArea(vector<int>& height) {
        
    int n=height.size();
    vector<pair<int, int>> num(n);

	map<int, set<int>> res;
	set<int> data;

	for (int i = 0; i < n; i++)
	{
        num[i].first=height[i];

		num[i].second = i;
		data.insert(i);
	}

	sort(num.begin(), num.end());

	int max = INT_MIN;
	for (int i = 0; i < n - 1; i++)
	{
		int index = num[i].second;
		data.erase(index);

		int it1 = *(data.begin());
		auto temp = data.end();
		temp--;

		int it2 = *(temp);

		int val1 = abs(it1 - index) * num[i].first;
		int val2 = abs(it2 - index) * num[i].first;

		max = std::max(max, std::max(val1, val2));
	}

      return(max);
    }
};