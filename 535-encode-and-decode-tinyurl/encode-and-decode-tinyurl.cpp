class Solution {
public:
    unordered_map<int, string> mp;
    int id = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[id] = longUrl;
        return "http://tinyurl.com/" + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(19);   // Extract ID
        return mp[stoi(key)];
    }
};