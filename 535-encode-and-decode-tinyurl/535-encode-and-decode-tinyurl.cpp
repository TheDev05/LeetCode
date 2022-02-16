/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution
{
public:
    // Encodes a URL to a shortened URL
    map<int, char> data2;
    string encode(string longUrl)
    {
        map<char, int> data1;
        for (int i = 0; i < longUrl.size(); i++)
        {
            if (data1.count(longUrl[i]) == false)
            {
                data1[longUrl[i]] = i;
                data2[i] = longUrl[i];
            }
        }

        string encoded;
        for (int i = 0; i < longUrl.size(); i++)
        {
            encoded += to_string(data1[longUrl[i]]);
            encoded += " ";
        }

        return (encoded);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string decoded, temp;
        for (auto i : shortUrl)
        {
            if (i == ' ')
            {
                int val = stoi(temp);
                decoded += data2[val];

                temp.clear();
            }
            else
                temp += i;
        }

        return (decoded);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
